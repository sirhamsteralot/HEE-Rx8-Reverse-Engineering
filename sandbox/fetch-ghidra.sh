#!/usr/bin/env bash
# Stage the official Ghidra 12.1.3 distribution for the sandbox image.
#
# sandbox/Dockerfile unpacks sandbox/ghidra-dist/*.zip into /opt/ghidra and
# points GHIDRA_HOME at it. The zip is third-party intake: it stays uncommitted
# (sandbox/ghidra-dist/ is gitignored) and the SHA-256 the build verifies is
# written next to it as SHA256SUMS.
#
# The pipeline is pinned to Ghidra 12.1.3 — utilities/scripts/rx8-pcm-pipeline/
# README.md, utilities/tools/ghidra/processor/README.md, and
# docs/investigations/60E15120_N3J1E/README.md:393.
#
# Usage:
#   ./fetch-ghidra.sh                 # resolve the release asset and download it
#   ./fetch-ghidra.sh --dry-run       # print the resolved asset URL only
#   ./fetch-ghidra.sh <asset-url>     # download a specific asset URL
set -euo pipefail

VERSION=${GHIDRA_VERSION:-12.1.3}
TAG="Ghidra_${VERSION}_build"
API="https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/tags/${TAG}"

here=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
dest="$here/ghidra-dist"

dry_run=0
url=""
for arg in "$@"; do
  case "$arg" in
    --dry-run) dry_run=1 ;;
    -h|--help) sed -n '2,19p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'; exit 0 ;;
    *) url=$arg ;;
  esac
done

command -v curl >/dev/null || { echo "fetch-ghidra: curl is required" >&2; exit 1; }

# The release publishes ghidra_<version>_PUBLIC_<build-date>.zip; take the URL
# from the release metadata instead of guessing the build date.
if [ -z "$url" ]; then
  url=$(curl -fsSL "$API" \
        | grep -o "https://[^\"]*ghidra_${VERSION}_PUBLIC_[0-9]*\.zip" \
        | head -1) || true
fi
[ -n "$url" ] || { echo "fetch-ghidra: no ghidra_${VERSION}_PUBLIC_*.zip asset in $TAG" >&2; exit 1; }

if [ "$dry_run" = 1 ]; then
  echo "$url"
  exit 0
fi

mkdir -p "$dest"
zip=$(basename "$url")
echo "fetch-ghidra: $url"
curl -fL --output "$dest/$zip" "$url"
( cd "$dest" && sha256sum "$zip" > SHA256SUMS && cat SHA256SUMS )
echo "fetch-ghidra: staged $dest/$zip"
echo "fetch-ghidra: next: SANDBOX_UID=\$(id -u) SANDBOX_GID=\$(id -g) docker compose build"

#!/usr/bin/env bash
# Run Vibe inside the agent box instead of on the host.
#
#   ./vibe.sh                       interactive session in /work/repo
#   ./vibe.sh "add a test for X"    session with an initial prompt
#   ./vibe.sh -p "list the files"   headless, one answer, exit
#   ./vibe.sh -- "anything"         everything after -- is passed to vibe
#
# The box has no host home, no SSH keys, no docker socket and no network route
# except the allowlisting proxy (see README.md), so a session started this way
# cannot touch the host beyond the read-only /src mount.
set -euo pipefail

here=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
cd "$here"

# Keep the egress proxy (the only route out) up for the session.
docker compose up -d egress >/dev/null

exec docker compose run --rm agent vibe "$@"

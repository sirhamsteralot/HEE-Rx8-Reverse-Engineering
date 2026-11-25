#!/usr/bin/env bash
# Boundary checks for the agent box. Run from this directory:
#   ./verify.sh
#
# Posture checks run inside the agent container; one of them writes a probe file
# into the mounted working tree and removes it again to prove the mount is the
# host checkout. The egress checks need the
# `egress` proxy running (`docker compose up -d egress`) and make outbound
# requests to the model API and to a destination outside the allowlist — run
# them only when you are happy for the box to reach the network at all.
set -uo pipefail

fail=0
check() { # name expected actual
  if [ "$2" = "$3" ]; then
    printf 'ok    %-28s %s\n' "$1" "$3"
  else
    printf 'FAIL  %-28s expected %s, got %s\n' "$1" "$2" "$3"
    fail=1
  fi
}

echo "== posture (inside the agent container) =="
check "uid"            "1000" "$(docker compose run --rm -T agent id -u 2>/dev/null | tr -d '\r')"
check "effective caps" "0000000000000000" \
  "$(docker compose run --rm -T agent grep CapEff /proc/self/status 2>/dev/null | awk '{print $2}' | tr -d '\r')"
# The repo is a mount, not a copy: a file written in the box has to show up in
# the host checkout. The probe is removed from the host side afterwards, so a
# failed write leaves nothing behind in the tree. REPO_PATH is resolved the way
# compose resolves it — relative to this directory.
repo_path="${REPO_PATH:-../..}"
case "$repo_path" in
  /*) host_root="$repo_path" ;;
  *)  host_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/$repo_path" && pwd) ;;
esac
probe="$host_root/.agent-box-probe"
rm -f "$probe"
docker compose run --rm -T agent touch /work/repo/.agent-box-probe >/dev/null 2>&1
if [ -e "$probe" ]; then mounted=yes; else mounted=no; fi
rm -f "$probe"
check "worktree is a mount" "yes" "$mounted"
# The mount keeps the host's uid/gid; git must still accept the checkout.
check "git works on the mount" "true" \
  "$(docker compose run --rm -T agent git -C /work/repo rev-parse --is-inside-work-tree 2>/dev/null | tr -d '\r')"
check "host docker socket" "absent" \
  "$(docker compose run --rm -T agent test -e /var/run/docker.sock && echo present || echo absent)"
check "sandbox network internal" "true" \
  "$(docker network inspect hee-agent-box_sandbox --format '{{.Internal}}' 2>/dev/null)"

# The box has no browser, so /usr/local/bin/xdg-open is the stub that prints the
# sign-in URL for the host instead of failing (xdg-open.sh). Checked statically:
# executing an opener is exactly what this box is not for.
check "opener stub (xdg-open)" "installed" \
  "$(docker compose run --rm -T agent sh -c 'test -x /usr/local/bin/xdg-open && grep -q "open this URL on your host" /usr/local/bin/xdg-open && echo installed || echo missing' 2>/dev/null | tr -d '\r')"
check "opener from BROWSER" "xdg-open" \
  "$(docker compose run --rm -T agent printenv BROWSER 2>/dev/null | tr -d '\r')"

if docker compose ps --status running --format '{{.Service}}' 2>/dev/null | grep -qx egress; then
  echo "== egress (through the proxy) =="
  code_allow=$(docker compose run --rm -T agent curl -x http://egress:8888 -s -o /dev/null \
      -w '%{http_code}' --max-time 20 https://api.mistral.ai/v1/models 2>/dev/null | tr -d '\r')
  if [ "$code_allow" = "000" ] || [ -z "$code_allow" ]; then
    printf 'FAIL  %-28s no response (allowlisted destination unreachable)\n' "mistral.ai reachable"; fail=1
  else
    printf 'ok    %-28s HTTP %s (reached the proxy, then the API)\n' "mistral.ai reachable" "$code_allow"
  fi

  # GitHub is allowlisted for git and API access; the proxy must let it out.
  code_github=$(docker compose run --rm -T agent curl -x http://egress:8888 -s -o /dev/null \
      -w '%{http_code}' --max-time 20 https://github.com/ 2>/dev/null | tr -d '\r')
  if [ -z "$code_github" ] || [ "$code_github" = "000" ]; then
    printf 'FAIL  %-28s no response (allowlisted destination unreachable)\n' "github.com reachable"
    fail=1
  else
    printf 'ok    %-28s HTTP %s (reached the proxy, then the host)\n' "github.com reachable" "$code_github"
  fi

  # For HTTPS the proxy refuses the CONNECT first, so curl reports no HTTP code
  # (000) plus "Received HTTP code 403 from proxy after CONNECT".
  deny_out=$(docker compose run --rm -T agent curl -x http://egress:8888 -sS -o /dev/null \
      -w '%{http_code}' --max-time 20 https://example.com 2>&1 | tr -d '\r')
  if printf '%s' "$deny_out" | grep -q '403'; then
    printf 'ok    %-28s %s\n' "example.com blocked" "proxy refused the CONNECT (403)"
  else
    printf 'FAIL  %-28s expected a 403 refusal, got %s\n' "example.com blocked" "$deny_out"
    fail=1
  fi

  # The CLI's feature-flag host (first-party Mistral); refusing it only costs a
  # warning per session, so it stays a separate, deletable allowlist line.
  code_flags=$(docker compose run --rm -T agent curl -x http://egress:8888 -s -o /dev/null \
      -w '%{http_code}' --max-time 20 https://experiments.mistral.services/ 2>/dev/null | tr -d '\r')
  if [ -z "$code_flags" ] || [ "$code_flags" = "000" ]; then
    printf 'FAIL  %-28s no response (allowlisted feature-flag host unreachable)\n' "mistral.services reachable"
    fail=1
  else
    printf 'ok    %-28s HTTP %s (reached the proxy, then the host)\n' "mistral.services reachable" "$code_flags"
  fi

  code_direct=$(docker compose run --rm -T agent curl -s -o /dev/null -w '%{http_code}' \
      --max-time 10 --noproxy '*' https://api.mistral.ai/v1/models 2>/dev/null | tr -d '\r')
  check "direct egress (no proxy)" "000" "$code_direct"
else
  echo "== egress skipped: start the proxy with 'docker compose up -d egress' =="
fi

exit "$fail"

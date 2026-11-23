#!/bin/sh
# xdg-open stand-in for the agent box, installed as /usr/local/bin/xdg-open.
#
# The box has no browser and no display attached. A real xdg-open fails there,
# and Vibe's browser sign-in treats a failed opener as fatal before it starts
# polling the console API — so the sign-in dies on the box side while the human
# is still typing a password into the host browser. This stub prints the URL
# instead and exits 0, so the CLI believes it handed the URL off and keeps the
# sign-in process alive; the poll and the key exchange then run inside the box
# over the allowlisted *.mistral.ai egress.
#
#   xdg-open https://console.mistral.ai/...    URL on stderr + ~/.vibe/opened-urls
#
# It is a stub, not a browser: only http(s) arguments are echoed. Anything else
# (a file, a mailto:) fails like a headless xdg-open does.
set -u

url=""
for arg in "$@"; do
  case "$arg" in
    http://*|https://*) url="$arg" ;;
  esac
done

if [ -z "$url" ]; then
  printf 'xdg-open: no browser in this container (only URL arguments are shown)\n' >&2
  exit 3
fi

printf '\n  no browser in this box — open this URL on your host:\n\n  %s\n\n' "$url" >&2

# The TUI redraws over the URL while it waits, so keep a copy to copy from.
if [ -n "${HOME:-}" ] && [ -d "${HOME}" ]; then
  printf '%s\n' "$url" >>"${HOME}/.vibe/opened-urls" 2>/dev/null || true
fi

# Openers that poll the child right after spawning read a dead process as
# "no browser available", so stay alive just long enough to look running.
sleep 1
exit 0

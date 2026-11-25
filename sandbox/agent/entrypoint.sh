#!/usr/bin/env bash
# Entrypoint for the agent box.
#
# Starts as root once, makes the agent's home volume writable for the non-root
# agent user, then drops privileges for everything else. /work/repo is a bind
# mount of the host working tree, so it is deliberately left alone: chowning it
# would rewrite ownership on the host.
set -euo pipefail

if [ "$(id -u)" = 0 ]; then
  chown -R agent:agent /home/agent 2>/dev/null || true
  exec gosu agent /usr/local/bin/entrypoint.sh "$@"
fi

# The mounted tree keeps the host's user and group ids, which need not be the
# box's (1000:1000); git would otherwise refuse the checkout as "dubious
# ownership". Safe here because the only writable repository is the mount.
git config --global --add safe.directory '*' 2>/dev/null || true

exec "$@"

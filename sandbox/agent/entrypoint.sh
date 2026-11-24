#!/usr/bin/env bash
# Entrypoint for the agent box.
#
# Starts as root once, makes the state volumes writable for the non-root agent
# user, seeds the private copy of the repo from the read-only /src mount, then
# drops privileges for everything else. Nothing here writes to the host tree.
set -euo pipefail

if [ "$(id -u)" = 0 ]; then
  chown -R agent:agent /work /home/agent 2>/dev/null || true

  if [ -n "${REPO_SRC:-}" ] && [ -d "$REPO_SRC" ]; then
    if [ ! -e /work/repo/.git ]; then
      echo "entrypoint: seeding a private copy of $REPO_SRC in /work/repo" >&2
      mkdir -p /work/repo
      cp -a "$REPO_SRC/." /work/repo/
      chown -R agent:agent /work/repo
    fi

    # Refresh the untracked intake folder on every start. The host tree is the
    # source of truth for new input; the copy keeps whatever the agent wrote
    # there. Update-only (-u, newest file wins) and additive — nothing is
    # deleted, and nothing outside input/ is touched, so the agent's git state
    # is never disturbed.
    if [ -d "$REPO_SRC/input" ]; then
      mkdir -p /work/repo/input
      cp -a -u "$REPO_SRC/input/." /work/repo/input/ \
        || echo "entrypoint: WARNING - input sync from $REPO_SRC/input was incomplete" >&2
      chown -R agent:agent /work/repo/input 2>/dev/null || true
    fi
  fi

  exec gosu agent /usr/local/bin/entrypoint.sh "$@"
fi

# The private copy belongs to the agent user, so git's ownership check is moot,
# but the mount keeps host timestamps and ids; allow it explicitly.
git config --global --add safe.directory '*' 2>/dev/null || true

exec "$@"

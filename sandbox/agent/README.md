# sandbox/agent — agent box with a host boundary

Runs an AI coding agent against this repo inside a container that has:

- **no host Docker socket** (nothing in the box can drive your daemon),
- **no host home directory** — no `~/.vibe`, no SSH keys, no `~/.gitconfig`,
- **no route off the machine except a default-deny egress proxy**,
- **only a read-only view of the repo**, with a disposable private copy to work in,
- **no capabilities, read-only root filesystem, non-root user**, capped PIDs,
  memory and CPUs.

This is the strongest boundary available with plain Docker on a host whose
distribution the microVM-based Docker Sandboxes (`sbx`) does not support. It is
**not** equivalent to a hypervisor boundary: containers share the host kernel,
so a kernel-level escape is a full compromise. Read [What this does not
protect](#what-this-does-not-protect) before trusting it.

```
host                                  agent box (container)
┌──────────────────────────────┐      ┌────────────────────────────────────┐
│ docker daemon  ──── no path ─┼──✕───┤ agent user (uid 1000), cap_add=[], │
│ ~/.vibe, ~/.ssh ─ no path ───┼──✕───┤ read_only rootfs, private copy in  │
│ $REPO (working tree) ────────┼──────┤ /work, read-only mount at /src     │
│                              │      └───────────────┬────────────────────┘
│                              │      ┌───────────────▼────────────────────┐
│                              │      │ sandbox network (internal: true)   │
│ egress proxy (tinyproxy) ◄───┼──────┤ only reachable peer: egress:8888   │
│  default deny + allowlist    │      └────────────────────────────────────┘
│         │                    │
│         ▼ allowed hosts only │
└──────────────────────────────┘
```

## Quick start

From this directory:

```sh
cp .env.example .env          # fill in MISTRAL_API_KEY; .env is gitignored
docker compose build
docker compose up -d egress   # allowlisting proxy
docker compose run --rm agent vibe        # agent session on the private copy
docker compose run --rm agent             # or a plain shell in the box
./verify.sh                               # boundary checks
```

The working tree is mounted read-only at `/src`; the first start copies it into
the `agent-work` volume (`/work/repo`) once, and the agent works there. Nothing
it writes reaches the host tree.

### Getting work out

The box cannot write to your repo by design. Review and pull changes explicitly:

```sh
docker compose exec agent git -C /work/repo status
docker compose exec agent git -C /work/repo diff
docker compose cp agent:/work/repo/my-file.c ./scratch/      # one path
docker compose exec agent git -C /work/repo bundle create /tmp/work.bundle main
docker compose cp agent:/tmp/work.bundle ./scratch/work.bundle
docker compose exec agent rm -rf /work/repo && docker compose run --rm agent true   # re-seed from /src
```

Treat what comes out the same way you would treat a pull request from a stranger:
`.git/hooks/`, CI configuration and build scripts are writable inside the box.

### Choosing the agent CLI

`AGENT` is a build argument, not an architectural choice:

```sh
AGENT=none   docker compose build agent     # same box, no agent installed
AGENT=vibe VIBE_VERSION=3.1.4 docker compose build agent   # default
```

The boundary is identical for every value. Another CLI needs only a line in the
`Dockerfile`'s install step plus its API host in `allowlist.txt`.

### Network policy

`allowlist.txt` is a tinyproxy default-deny list of extended regexes matched
against the destination host; HTTPS (443/563) is the only permitted protocol, so
git-over-SSH and raw TCP egress have no path out. Adding a destination:

```sh
printf '^(.+\\.)?example\\.com$\n' >> allowlist.txt
docker compose build egress && docker compose up -d egress
```

## What this does not protect

- **The host kernel.** Containers share it. `cap_drop: ALL`, a read-only root
  filesystem, `no-new-privileges` and resource limits shrink the attack surface;
  they do not make a kernel exploit survivable. Docker's default seccomp profile
  applies; no custom profile is shipped.
- **The mounted repo is readable in full.** Read-only stops writes, not reads:
  untracked files, `.gitignore`d files and anything else in the working tree are
  visible inside the box. Keep secrets out of the working tree.
- **The model credential is inside the box.** There is no host-side credential
  proxy here, so `MISTRAL_API_KEY` is visible to every process in the container.
  Pass it through `.env`, never bake it into an image.
- **The `egress` proxy is trusted.** It runs on the same machine, with a
  read-only root filesystem, no capabilities and its own unprivileged user, but
  it is the only container with a route out — treat a proxy compromise as an
  egress compromise.
- **Host-side `docker compose` invocation still runs as you.** Lifecycle,
  build-arg and entrypoint commands you author run with your privileges, as with
  any compose project.

## What was verified

`./verify.sh` runs all of it and every check passes:

| Check | Result |
|---|---|
| `id` inside the box | `uid=1000(agent) gid=1000(agent)` |
| effective capabilities | `CapEff: 0000000000000000` |
| write to the `/src` mount | refused — `Read-only file system` |
| `/var/run/docker.sock` in the box | absent |
| `hee-agent-box_sandbox` network | `internal=true` — no gateway, only the proxy is reachable |
| allowlisted destination (`api.mistral.ai`) via the proxy | `HTTP 401` — the proxy let it out, the API rejected the unauthenticated call |
| non-allowlisted destination (`github.com`) via the proxy | proxy refuses the `CONNECT` (`403`) |
| direct egress without the proxy | no response — the sandbox network has no route out |
| `docker compose config` | `read_only: true`, `cap_drop: [ALL]`, `no-new-privileges:true`, `pids_limit: 2048`, `/src` bind `read_only: true`, no host binds beyond `/src` |
| `vibe --version` / `python -m pytest --version` | `vibe 3.1.4` / `pytest 9.2.0` |
| `python -m pytest tests/` in `/work/repo` | 1 failed, 374 passed, 7 errors — identical to the host run on the same tree (`test_extract_scalars.py`, `test_defs_upstream_pin.py`, from uncommitted `data/definitions/` and a drifted `submodules/RX8Defs` gitlink) |

## Limits

- The box persists in named volumes (`agent-work`, `agent-home`) until you
  `docker compose down -v`; the agent CLI's own state and config live there.
- The emulator UI binds loopback inside the container
  (`make_server()` in [`ui.py`](../../utilities/scripts/emu/ui.py)), so it is not
  reachable from the host from inside the box.
- Package installs inside the box must target the writable volumes —
  `pip install --user …`, `uv tool install …` — because the root filesystem is
  read-only. `apt-get install` needs a rebuilt image.
- The repo copy is seeded once per volume. `docker compose down -v` or
  `rm -rf /work/repo` re-seeds from the current working tree.
- For hypervisor-grade isolation — a separate kernel per sandbox, and credential
  injection that keeps the model API key on the host — Docker Sandboxes (`sbx`)
  is the tool. It supports Ubuntu 24.04+, macOS and Windows only, which is why
  the boundary above is what this repository can run today.

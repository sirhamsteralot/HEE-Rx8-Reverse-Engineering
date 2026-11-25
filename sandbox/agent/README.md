# sandbox/agent — agent box with a host boundary

Runs an AI coding agent against this repo inside a container that has:

- **no host Docker socket** (nothing in the box can drive your daemon),
- **no host home directory** — no `~/.vibe`, no SSH keys, no `~/.gitconfig`,
- **no route off the machine except a default-deny egress proxy**,
- **exactly one host path: the repo working tree, mounted read-write** — the
  agent edits this checkout in place (see [The mounted working
  tree](#the-mounted-working-tree)),
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
│ ~/.vibe, ~/.ssh ─ no path ───┼──✕───┤ read_only rootfs                   │
│ $REPO (working tree) ────────┼──────┤ /work/repo = that tree, read-write │
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
docker compose run --rm agent vibe        # agent session in the working tree
docker compose run --rm agent             # or a plain shell in the box
./verify.sh                               # boundary checks
```

The same on Windows, from PowerShell:

```powershell
Copy-Item .env.example .env   # fill in MISTRAL_API_KEY; .env is gitignored
docker compose build
.\vibe.ps1                    # starts the egress proxy, then an agent session
docker compose run --rm agent # or a plain shell in the box
```

[`vibe.ps1`](vibe.ps1) is the PowerShell port of [`vibe.sh`](vibe.sh): it takes
the same arguments, starts the same proxy and returns the container's exit code.
Each host uses its own wrapper — `./vibe.sh` wherever bash is available (Linux,
Git Bash), `.\vibe.ps1` from PowerShell (PowerShell 7 on Linux, or Windows
PowerShell 5.1 / PowerShell 7 on Windows) — and both drive the same compose file
and the same containers, so a session started one way is visible to the other.
The boundary checks stay in `verify.sh`, which has no PowerShell port — run it
from Git Bash.

## The mounted working tree

The working tree is bind-mounted read-write at `/work/repo` (compose resolves it
from `REPO_PATH`, default `../..` — this repository), and that is the directory
the session starts in. There is **no copy**: a file the box writes is the same
file your editor and `git` see on the host, immediately, with no export step.

That is the whole point — and the whole trade-off:

| | |
|---|---|
| commits, uncommitted work | visible on both sides at once; no bundle/copy step |
| untracked and `.gitignore`d files | the box can read **and** delete them, like any file in the tree |
| `.git/` | writable from inside — history and hooks are not a safety net |
| host uid/gid | files the box creates carry the box's ids (`1000:1000`), not necessarily yours |
| a second checkout | keep the primary tree out of reach by pointing `REPO_PATH` elsewhere |

To mount something other than this checkout — typically a throwaway clone, which
restores the old read-only-remote feel:

```sh
git clone --shared . /tmp/agent-scratch        # or: git worktree add /tmp/agent-scratch main
REPO_PATH=/tmp/agent-scratch docker compose run --rm agent vibe
```

The mount is the only host path the box sees, and `entrypoint.sh` never chowns
it: ownership on the host is left alone. Because the mount keeps host ids, git
needs the box's `safe.directory` entry, which the entrypoint sets.

### Reviewing what a session changed

The box wrote straight into your checkout, so review it as ordinary local work:

```sh
git status                    # on the host
git diff
git add -p
```

Nothing leaves the box by itself: no push happens unless you put a GitHub
credential inside it (see [Network policy](#network-policy) and [What this does
not protect](#what-this-does-not-protect)).

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

The list itself is three groups:

| pattern | what it covers |
|---|---|
| `^(.+\.)?mistral\.ai$` | the model API (`api.`, plus the regional `api.us.`/`api.eu.` hosts) and the whole sign-in flow: the console's sign-in start, poll and key-exchange calls (`console.mistral.ai/api/vibe/sign-in…`), the tenant/whoami lookups (`chat.mistral.ai`) and the OIDC issuer (`auth.mistral.ai`) all match this pattern |
| `^experiments\.mistral\.services$` | the CLI's first-party feature-flag evaluation (GrowthBook). Refusing it costs a `GrowthBook eval request failed` warning per session in `~/.vibe/logs/vibe.log` and blocks nothing — delete the line if you would rather the box did not report flag evaluations |
| `^github\.com$`, `^api\.github\.com$`, `^codeload\.github\.com$`, `^raw\.githubusercontent\.com$`, `^objects\.githubusercontent\.com$`, `^media\.githubusercontent\.com$`, `^github-cloud\.s3\.amazonaws\.com$` | GitHub: `git clone`/`fetch`/`push` over HTTPS, the REST/GraphQL API (the `gh` CLI and the GitHub connector), archive downloads, raw files, release assets and git-lfs objects. Delete the block to keep the box off GitHub |

Signing in needs **no** additional allowlist entry. What it needs is a browser,
and the box has none: see [Signing in](#signing-in).

## Running your Vibe inside the box

`./vibe.sh` — `.\vibe.ps1` from PowerShell — wraps the three moving parts (start
the egress proxy, run the agent container, pass your arguments through):

```sh
./vibe.sh                        # interactive session in /work/repo
./vibe.sh "add a test for the O2 monitor labels"   # session with a first prompt
./vibe.sh -p "list the ROM profiles"               # headless: one answer, then exit
./vibe.sh --resume                                # continue a session from the box
```

```powershell
.\vibe.ps1                       # interactive session in /work/repo
.\vibe.ps1 "add a test for the O2 monitor labels"  # session with a first prompt
.\vibe.ps1 -p "list the ROM profiles"              # headless: one answer, then exit
.\vibe.ps1 --resume                                # continue a session from the box
```

Both wrappers forward every argument verbatim — a quoted prompt stays one
argument, `--` and `--resume` reach `vibe` as written — and exit with the code
`docker compose run` returned. The PowerShell wrapper resolves the compose file
from its own location, so it works from any directory and still picks up
`sandbox/agent/.env`; it needs nothing on the host beyond `docker` (Windows
PowerShell 5.1 and PowerShell 7 run it, PowerShell 7 also on Linux, and a
missing `docker` exits `127`).

Equivalently, without the wrapper:

```sh
docker compose up -d egress
docker compose run --rm agent vibe
```

### Signing in

`vibe --setup` offers browser sign-in. The box has no browser, so `xdg-open` is a
stub ([`xdg-open.sh`](xdg-open.sh), installed as `/usr/local/bin/xdg-open` and
selected via `BROWSER=xdg-open`). It prints what the CLI wanted to open instead
of failing the opener — a failed opener aborts the sign-in *before* the poll
starts, which is why signing in on the host on its own never completes:

```
  no browser in this box — open this URL on your host:

  https://console.mistral.ai/…
```

Open that URL in your host browser and sign in there. The box keeps polling
`console.mistral.ai` (allowlisted) while you do, so the setup finishes the moment
you are done; every URL the stub printed is appended to `~/.vibe/opened-urls` in
the `agent-home` volume, because the TUI redraws over it while it waits. The
resulting key is written to `~/.vibe/.env`, also in the home volume.

### Where the API key goes

Two options, both keeping the credential out of your host shell and image:

```sh
# 1. the setup screen, at the box's own prompt: sign in as above, or use its
#    "Paste it manually instead" entry — the key lands in the home volume
docker compose run --rm agent vibe --setup

# 2. or hand it to the container through an untracked env file
cp .env.example .env    # then set MISTRAL_API_KEY=
```

The key is visible to processes inside the container either way — there is no
host-side credential proxy here (that is what `sbx` adds, see below).

### What the session sees

| | |
|---|---|
| working directory | `/work/repo` — the host working tree, bind-mounted read-write (unless `REPO_PATH` points at another checkout) |
| `~/.vibe` (config, sessions, skills caches) | the `agent-home` volume, so `--continue`/`--resume` work across runs and are wiped by `docker compose down -v` |
| repo tooling | `.vibe/plugins/hee-re/` is part of the mounted tree, so the hee-re plugin and its MCP server run **inside** the box with the box's python |
| browser | none: `xdg-open` is the stub that prints the URL for you to open on the host (see [Signing in](#signing-in)) |
| your host | nothing but the mounted working tree: no `~/.vibe` settings, no model aliases or custom agents, no SSH agent, no docker socket, no connectors host-side |

Vibe prompts once for trust in an unfamiliar directory; `./vibe.sh --trust`
skips it for that invocation. For unattended runs, bound the damage with
`--approval-policy`, `--max-turns`, `--max-price` and `--time-limit`.

## If you add Docker Sandboxes (`sbx`) later

`sbx` is not used here (it supports Ubuntu 24.04+, macOS and Windows only), but
this box maps onto an `sbx` **kit**: a
directory holding `<stem>.yaml` and `<stem>.dockerfile`, where the descriptor
declares the tool, its network rules and its credential handling, and the
Dockerfile installs it. A Vibe mixin would be, in outline:

```yaml
# syntax=docker/sandbox-kit:3
schemaVersion: "3"
kind: mixin
args:
  version:
    default: "3.1.4"
    pattern: '^[0-9]+\.[0-9]+\.[0-9]+$'
    buildArg: VIBE_VERSION
capabilities:
  - type: com.docker.sandbox/network-policy@1
    config:
      runtime:
        allow: ["api.mistral.ai:443"]
  - type: com.docker.sandbox/credential@1
    config:
      service: mistral
      phase: runtime
      apiKey:
        name: MISTRAL_API_KEY
        proxyManaged: true
        inject:
          - domain: api.mistral.ai
            header: Authorization
            format: "Bearer %s"
```

Run it against Docker's shell workload with `sbx run shell --kit ./vibe-mixin`,
storing the key host-side with `sbx secret set mistral`. The difference from this
folder is that the key never enters the sandbox (the host proxy swaps a
placeholder for the real header) and the isolation boundary is the hypervisor
instead of the kernel's namespaces. The file above is a sketch, not something
that has been built or run here.

## What this does not protect

- **The host kernel.** Containers share it. `cap_drop: ALL`, a read-only root
  filesystem, `no-new-privileges` and resource limits shrink the attack surface;
  they do not make a kernel exploit survivable. Docker's default seccomp profile
  applies; no custom profile is shipped.
- **The working tree is writable from inside the box.** The mount is the one host
  path the box can change: it can rewrite, add and delete any file in the
  checkout, `.git/` included, so history and hooks are not a safety net and
  uncommitted work can be lost. Commit or push before a session and review
  `git status` after; for a boundary that does not include your primary checkout,
  point `REPO_PATH` at a scratch clone (see [The mounted working
  tree](#the-mounted-working-tree)).
- **The mounted repo is readable in full.** Untracked files, `.gitignore`d files
  and anything else in the working tree are visible inside the box. Keep secrets
  out of the working tree.
- **The model credential is inside the box.** There is no host-side credential
  proxy here, so `MISTRAL_API_KEY` is visible to every process in the container.
  Pass it through `.env`, never bake it into an image.
- **GitHub egress is content, not trust.** With the GitHub block allowlisted the
  box can read any public repository (and whatever that repository's build
  scripts do), and any GitHub credential you give it — a token in `.env`, a
  helper in `~/.git-credentials` — turns that line into a push path. The box
  ships with no GitHub credentials of its own, so nothing pushes unless you put
  one there.
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
| write to `/work/repo` in the box | lands in the host working tree — probe file created in the box, seen on the host, removed again |
| `git -C /work/repo rev-parse --is-inside-work-tree` in the box | `true` — the mount keeps host ids, and the entrypoint's `safe.directory` entry makes git accept it |
| `/var/run/docker.sock` in the box | absent |
| `hee-agent-box_sandbox` network | `internal=true` — no gateway, only the proxy is reachable |
| allowlisted destination (`api.mistral.ai`) via the proxy | `HTTP 401` — the proxy let it out, the API rejected the unauthenticated call |
| allowlisted destination (`github.com`) via the proxy | `HTTP 200` — the proxy let it out and the host answered |
| `git ls-remote https://github.com/git/git HEAD` in the box | resolves `f7de8145…` — git over HTTPS works end to end through the proxy |
| non-allowlisted destination (`example.com`) via the proxy | proxy refuses the `CONNECT` (`403`) |
| allowlisted feature-flag host (`experiments.mistral.services`) via the proxy | `HTTP 404` — the proxy let it out, the host answered for `/` (before the entry: `Proxying refused on filtered domain`) |
| browser opener in the box | `/usr/local/bin/xdg-open` is the stub and `BROWSER=xdg-open` — every opener call reports the URL for the host instead of failing |
| direct egress without the proxy | no response — the sandbox network has no route out |
| `docker compose config` | `read_only: true`, `cap_drop: [ALL]`, `no-new-privileges:true`, `pids_limit: 2048`, exactly one host bind — the working tree at `/work/repo` (read-write) — plus the `agent-home` volume |
| `./vibe.sh --version` | `vibe 3.1.4` — the wrapper starts the proxy and runs the CLI inside the box |
| `.\vibe.ps1 --version` | `vibe 3.1.4`, exit `0` — the PowerShell wrapper starts the same proxy and runs the same command inside the box; an unknown flag returns the CLI's exit code `1` (checked from Windows PowerShell 5.1; the same script under PowerShell 7.4 on Linux, with a stub `docker`, makes the same two compose calls and returns the same exit code) |
| `python -m pytest --version` | `pytest 9.2.0` |
| `python -m pytest tests/` in `/work/repo` | 388 passed, 7 errors in 2m41s — the box runs the suite on the host tree itself; the 7 errors are `tests/test_defs_upstream_pin.py` refusing the drifted `submodules/RX8Defs` gitlink (`39d98a0a…` checked out vs `d4140dc2…` committed), which is host state and fails the same way on the host |

Not run here: a live Vibe session against the model API, and a browser sign-in
end to end — both need your key and your account. The proxy's allow paths are the
rows in [Network policy](#network-policy); the sign-in poll and exchange use the
first of them.

The `vibe.ps1` `--version` row ran from Windows PowerShell 5.1 against a
`core.autocrlf` checkout, i.e. a CRLF working tree; the image normalizes the
scripts and the proxy config it copies, so that checkout builds and runs the
same box, and an LF checkout (Linux) builds it unchanged.

## Limits

- The box persists in the `agent-home` named volume until you
  `docker compose down -v`; the agent CLI's own state and config live there. The
  repo is not in a volume: it is the mount, so `down -v` never touches it.
- The emulator UI binds loopback inside the container
  (`make_server()` in [`ui.py`](../../utilities/scripts/emu/ui.py)), so it is not
  reachable from the host from inside the box.
- Package installs inside the box must target the writable volumes —
  `pip install --user …`, `uv tool install …` — because the root filesystem is
  read-only. `apt-get install` needs a rebuilt image.
- The box runs as `1000:1000`, so files it creates in the mount carry those ids
  on the host even when your user is a different one. Mount a clone you own (see
  [The mounted working tree](#the-mounted-working-tree)) if that matters.
- An `agent-work` volume from an older copy-based version of this box is no
  longer used and can be dropped: `docker volume rm hee-agent-box_agent-work`.
- The image strips CR from the scripts and the proxy config it copies, so a
  Windows checkout (`core.autocrlf`) builds the same box. Scripts executed from
  the checked-out tree keep the checkout's line endings, so a CRLF tree breaks
  them inside any Linux container.
- There is no browser in the box: anything that wants one — the CLI's sign-in,
  a connector's OAuth page — reaches the `xdg-open` stub, which only prints the
  URL. Copy it to the host, and keep the box's process alive (the sign-in poll
  gives up after the CLI's own timeout, so finish in the browser promptly).
- For hypervisor-grade isolation — a separate kernel per sandbox, and credential
  injection that keeps the model API key on the host — Docker Sandboxes (`sbx`)
  is the tool. It supports Ubuntu 24.04+, macOS and Windows only, which is why
  the boundary above is what this repository can run today.

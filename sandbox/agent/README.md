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

GitHub is allowlisted (see [Network policy](#network-policy)), but the box holds
no GitHub credentials, so work still leaves the way above unless you deliberately
put a token inside it — a `gh` login or a token in `.env` makes `git push` from
the box possible, and that is then a push path you opened.

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

`./vibe.sh` wraps the three moving parts (start the egress proxy, run the agent
container, pass your arguments through):

```sh
./vibe.sh                        # interactive session in /work/repo
./vibe.sh "add a test for the O2 monitor labels"   # session with a first prompt
./vibe.sh -p "list the ROM profiles"               # headless: one answer, then exit
./vibe.sh --resume                                # continue a session from the box
```

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
| working directory | `/work/repo` — the private copy seeded from the read-only `/src` mount |
| `~/.vibe` (config, sessions, skills caches) | the `agent-home` volume, so `--continue`/`--resume` work across runs and are wiped by `docker compose down -v` |
| repo tooling | `.vibe/plugins/hee-re/` is part of the copied tree, so the hee-re plugin and its MCP server run **inside** the box with the box's python |
| browser | none: `xdg-open` is the stub that prints the URL for you to open on the host (see [Signing in](#signing-in)) |
| your host | nothing: no `~/.vibe` settings, no model aliases or custom agents, no SSH agent, no docker socket, no connectors host-side |

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
- **The mounted repo is readable in full.** Read-only stops writes, not reads:
  untracked files, `.gitignore`d files and anything else in the working tree are
  visible inside the box. Keep secrets out of the working tree.
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
| write to the `/src` mount | refused — `Read-only file system` |
| `/var/run/docker.sock` in the box | absent |
| `hee-agent-box_sandbox` network | `internal=true` — no gateway, only the proxy is reachable |
| allowlisted destination (`api.mistral.ai`) via the proxy | `HTTP 401` — the proxy let it out, the API rejected the unauthenticated call |
| allowlisted destination (`github.com`) via the proxy | `HTTP 200` — the proxy let it out and the host answered |
| `git ls-remote https://github.com/git/git HEAD` in the box | resolves `f7de8145…` — git over HTTPS works end to end through the proxy |
| non-allowlisted destination (`example.com`) via the proxy | proxy refuses the `CONNECT` (`403`) |
| allowlisted feature-flag host (`experiments.mistral.services`) via the proxy | `HTTP 404` — the proxy let it out, the host answered for `/` (before the entry: `Proxying refused on filtered domain`) |
| browser opener in the box | `/usr/local/bin/xdg-open` is the stub and `BROWSER=xdg-open` — every opener call reports the URL for the host instead of failing |
| direct egress without the proxy | no response — the sandbox network has no route out |
| `docker compose config` | `read_only: true`, `cap_drop: [ALL]`, `no-new-privileges:true`, `pids_limit: 2048`, `/src` bind `read_only: true`, no host binds beyond `/src` |
| `./vibe.sh --version` | `vibe 3.1.4` — the wrapper starts the proxy and runs the CLI inside the box |
| `python -m pytest --version` | `pytest 9.2.0` |
| `python -m pytest tests/` in `/work/repo` | 1 failed, 374 passed, 7 errors — identical to the host run on the same tree (`test_extract_scalars.py`, `test_defs_upstream_pin.py`, from uncommitted `data/definitions/` and a drifted `submodules/RX8Defs` gitlink) |

Not run here: a live Vibe session against the model API, and a browser sign-in
end to end — both need your key and your account. The proxy's allow paths are the
rows in [Network policy](#network-policy); the sign-in poll and exchange use the
first of them.

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

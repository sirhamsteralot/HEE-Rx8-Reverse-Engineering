# sandbox/

A Docker image carrying everything this repo needs to run its own verification
steps, so a run does not depend on what happens to be installed on the machine:

- `python -m pytest tests/` (the whole suite, including the generator
  regeneration tests),
- the emulator in `utilities/scripts/emu/`,
- the pipeline validators in `utilities/scripts/rx8-pcm-pipeline/`,
- the C host tests in `reverse-engineered/reimplementation/`,
- the Ghidra-dependent `rebuild.sh` steps, when the Ghidra layer is staged.

The repo itself is **not** baked into the image: `compose.yaml` bind-mounts it
at `/work/repo`, so the image stays a toolchain and your working tree stays on
the host. This is a build/test sandbox, not a security boundary — the repo is
mounted read-write and nothing inside the container is isolated from your files.

## Quick start

Run the commands from this directory.

```sh
SANDBOX_UID=$(id -u) SANDBOX_GID=$(id -g) docker compose build
docker compose run --rm sandbox python -m pytest tests/
docker compose run --rm sandbox                                  # interactive shell
docker compose run --rm sandbox python utilities/scripts/emu/emu.py \
    --profile 60E15120_N3J1E --cycles 1000000
```

The `SANDBOX_UID`/`SANDBOX_GID` build arguments create the container account
with your host IDs, so git, pytest and the generator scripts write files that
your host account still owns. They default to `1000`.

The build context is this directory (`sandbox/`), not the repository root, so a
rebuild does not stream the ~500 MB working tree to the daemon.

## What is inside

| Component | Version | Needed for | Reference |
|---|---|---|---|
| Python | 3.13 | `tests/`, `utilities/scripts/` (all other imports are standard library) | [README.md](../README.md) quick start |
| pytest | 9.2.0 | `tests/` | [tests/README.md](../tests/README.md) |
| git + git-lfs | 2.47 / 3.6 | submodule checkout, LFS-backed ROMs/PDFs/backups | [README.md](../README.md) quick start |
| gcc / make | 14 | `reverse-engineered/reimplementation/` host tests (`-Werror`) | [tests/README.md](../tests/README.md) |
| OpenJDK | 21 | `rebuild.sh`; Ghidra 12.1.3 requires JDK 21+ | [utilities/README.md](../utilities/README.md), [pipeline README](../utilities/scripts/rx8-pcm-pipeline/README.md) |
| Ghidra | 12.1.3, optional | the `GHIDRA_HOME` steps of `rebuild.sh` | [processor README](../utilities/tools/ghidra/processor/README.md) |

ROM binaries, submodule content and LFS objects are not installed by the image —
they come from the bind-mounted working tree, so `git submodule update --init`
and `git lfs pull` stay host-side operations.

## Ghidra layer

`sandbox/Dockerfile` unpacks `sandbox/ghidra-dist/*.zip` into `/opt/ghidra`,
verifies it against `ghidra-dist/SHA256SUMS` when that file is present, and
exports `GHIDRA_HOME=/opt/ghidra`. With nothing staged the image simply has no
Ghidra: everything except `rebuild.sh` still runs, and `rebuild.sh` fails at its
own `GHIDRA_HOME` check.

To stage the distribution (third-party intake — it is uncommitted,
`sandbox/ghidra-dist/` is gitignored):

```sh
./fetch-ghidra.sh          # resolves the Ghidra 12.1.3 release asset, downloads it, writes SHA256SUMS
./fetch-ghidra.sh --dry-run  # print the asset URL only
SANDBOX_UID=$(id -u) SANDBOX_GID=$(id -g) docker compose build
docker compose run --rm sandbox bash -lc \
  'GHIDRA_HOME=/opt/ghidra bash utilities/scripts/rx8-pcm-pipeline/rebuild.sh RX8_REPRO'
```

`/opt/ghidra` is owned by the container account because `rebuild.sh` copies the
SH-2E processor configuration into `$GHIDRA_HOME/Ghidra/Processors/SuperH/data/languages`
and runs its `sleigh` compiler there. Ghidra project databases land in
`${GHIDRA_WORK:-input/ghidra-work}` inside the mounted repo, matching the host
default in [`paths.py`](../utilities/scripts/rx8-pcm-pipeline/paths.py); they
stay uncommitted.

## What was verified

Everything below ran inside `docker compose run --rm sandbox` against this
working tree:

| Command | Result |
|---|---|
| `python -m pytest tests/` | 1 failed, 374 passed, 7 errors — the same two files (`test_extract_scalars.py`, `test_defs_upstream_pin.py`) fail identically on the host against the same uncommitted `data/definitions/` and drifted `submodules/RX8Defs` gitlink |
| `python utilities/scripts/hash_binaries.py --check` | `manifest OK (1 file(s))` |
| `validate_export.py` | exit 0 — `input_sha256_verified: true`, `instruction_bytes_verified: 337184`, `exact_reference_matches_verified: 1833` |
| `validate_reports.py` | `"result": "PASS"`, `failures: []` |
| `verify_claims.py` | `"result": "PASS"`, `failures: []` |
| `verify_math_units.py` | 16 shift pairs, 10007 fixed-point cases, 70 constant pairs |
| `verify_readability.py` | `AssertionError` — reproduces the host failure against the same tree |
| `emu.py --profile 60E15120_N3J1E --cycles 1000000` | ROM SHA-256 verified, 1 000 000 instructions, final pc `0x00003dac` |
| `cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off … test_rx8_math.c` | compiles and the test binary exits 0 |

Not verified: `fetch-ghidra.sh`'s download and the resulting Ghidra layer (the
distribution is not part of this tree), and `rebuild.sh`, which needs that
layer. Record those results in the investigation doc of the change that relies
on them.

## Limits

- The emulator UI binds loopback inside the container
  (`make_server()` in [`ui.py`](../utilities/scripts/emu/ui.py) uses `127.0.0.1`),
  so the `ports:` mapping in `compose.yaml` is commented out. Run the UI on the
  host; publishing it needs a bind-address option the UI does not have yet.
- The image is a toolchain, not a hermetic environment: the bind mount means
  installed packages, caches and git state are shared with the host tree, and
  `docker compose run` keeps `pip-cache`/`ghidra-settings` volumes between runs.
- Docker Sandboxes (`sbx`, microVM isolation for agents) is a different tool and
  is not used here.

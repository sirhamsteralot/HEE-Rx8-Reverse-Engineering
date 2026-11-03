# input/ — raw intake (never committed)

Drop zone for raw, unvetted material related to the HEE RX-8 effort:

- firmware dumps / `.bin` files before they are verified and promoted
- prior efforts and notes from other people
- cloned third-party git repositories and source trees
- reference downloads (manuals, tools, datasets, saved web pages)

## Rules

- **Nothing inside `input/` is committed to git** (see `../.gitignore`: `input/*` is
  ignored, only this README is tracked). This keeps third-party code, arbitrary
  binaries, and license-unclear material out of the repo.
- Nested git clones are fine here — they stay untracked.
- Treat everything here as untrusted input: verify hashes, provenance, and licensing
  before relying on it.

## Status

`Tuning-merged/` (union of `Tuning-29-10-2026` + `Tuning-30-10-2026`, newer wins)
was promoted into the tracked folders on 2026-10-31 and later removed from `input/`.
The upstream git repositories now live as **read-only submodules** under
`../submodules/` (see [`../docs/references/README.md`](../docs/references/README.md)).
2026-10-31: the pipeline (`../utilities/scripts/rx8-pcm-pipeline/`) no longer needs
`input/Tuning-merged` — its `paths.py` shim resolves the old workspace keys to the
promoted tracked layout (`../reverse-engineered/`, `../docs/investigations/`,
`../data/labels/`, `../submodules/`). Ghidra project DBs (never committed) go to
`input/ghidra-work/` via `GHIDRA_WORK`.

2026-10-31: `mazda-rx-8-pcm-pinout-series-1.md` (text PCM pinout derived from
`13Electrical.pdf`, which remains ground truth) was promoted to
[`../docs/architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md`](../docs/architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md) (with a
provenance header added there) and then removed from `input/`, like
`Tuning-merged/` before it. The tracked copy is the one to read and edit.

2026-10-31: byte-identical duplicates of submodule files were removed from the
tracked folders (10 stock ROMs, 3 captures, 3 Ghidra `.gar` archives) — they are
referenced via `../submodules/Mazda_RX8_PCM_ReverseEngineering/` at its pinned
commit instead. See [`../docs/references/README.md`](../docs/references/README.md).

2026-10-31: the saved RX8Club.com user-guide thread (pages 1–9) was reviewed;
usable facts + OCR of screenshots extracted to `../docs/references/`
(`rx8club-user-guide-thread.md`, `rx8club-ocr/`, `rx8club-inline-defs.tsv`).

2026-10-31: `Proton Drive Download - 2026-10-31.zip` and `RX8 666p_9_files.zip`
extracted under `extracted-proton/` and `extracted-666p/` and promoted: the stock
N3ZHEC factory ROM → `../binaries/dumps/` (further reads byte-identical to submodule
stock ROMs are referenced, not copied); the user-tuned ROMs in the same
bundle were deliberately not retained. Logs → `../data/logs/`, NR666P tune
containers → `../data/tunes/`.

2026-11-01: `input/` emptied (cleanup) — everything except this README was removed:
the 4 .bin reads (SHA-256-audited 2026-11-01: 3 byte-identical to submodule stock
ROMs, 1 a 2-byte NMI patch for simulation), the 2 reference-doc zips and RX8Club raw
pages (content already promoted to `../docs/references/`), scratch scripts + `work/`,
the Ghidra 12.1.2 install + project DBs + export recipe/log, and the saved Renesas
simulator traces. Reacquire on demand: Ghidra 12.1.2 PUBLIC + JDK 21 (`GHIDRA_HOME`),
the Proton Drive zip, the RX8Club thread pages, Renesas traces via the Sdsh2e
procedure in `../utilities/scripts/emu/README.md` (save into `input/`), and the
sim-only patched ROM by applying the 2-byte patch at 0x8f0 (`89 fb` → `00 09`)
to a copy of the stock 60E15120_N3J1E ROM.

## Promotion path

When something in `input/` proves useful, don't reference it from tracked files —
copy/promote it into the proper home with provenance:

| Material | Goes to |
|---|---|
| Verified firmware dump | `binaries/` + row in `binaries/manifest.csv` |
| Useful code from another project | summarized/ported into `reverse-engineered/` with attribution in the investigation doc |
| External doc / link | `docs/references/` (URL + access date) |
| Extracted tables/strings | `data/` with source hash + address range |
| Data logs | `data/logs/` (golden fixtures for the emulator's virtual OBD port) |
| Tune containers/notes | `data/tunes/` (context only, never flashed) |
| Reusable script | `utilities/scripts/` |

2026-11-03: `4EngineControl.pdf` (Mazda RX-8 workshop manual "RX8 – Engine
Diagnostics & Control", PDF created 2003-11-21) received. Its DTC TABLE section was
parsed to the tracked `data/dtc/mazda_dtc_table.tsv` and merged into
`data/dtc/pcodes.tsv` (Mazda wording preferred in def descriptions) — see
`docs/investigations/60E15120_N3J1E/dtc_control_report.md` §5b. The PDF itself stays
here uncommitted (rule 4).

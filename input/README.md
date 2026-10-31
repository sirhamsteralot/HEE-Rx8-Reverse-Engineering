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
`../submodules/` (see `../docs/references/README.md`).

2026-10-31: `mazda-rx-8-pcm-pinout-series-1.md` (text PCM pinout derived from
`13Electrical.pdf`, which remains ground truth) was promoted to
`../docs/architecture/hardware/`.

2026-10-31: byte-identical duplicates of submodule files were removed from the
tracked folders (10 stock ROMs, 3 captures, 3 Ghidra `.gar` archives) — they are
referenced via `../submodules/Mazda_RX8_PCM_ReverseEngineering/` at its pinned
commit instead. See `../docs/references/README.md`.

2026-10-31: the saved RX8Club.com user-guide thread (pages 1–9) was reviewed;
usable facts + OCR of screenshots extracted to `../docs/references/`
(`rx8club-user-guide-thread.md`, `rx8club-ocr/`, `rx8club-inline-defs.tsv`).

2026-10-31: `Proton Drive Download - 2026-10-31.zip` and `RX8 666p_9_files.zip`
extracted under `extracted-proton/` and `extracted-666p/` and promoted: 4 ROMs →
`../binaries/dumps/` (2 more were byte-identical to submodule stock ROMs and are
referenced, not copied), logs → `../data/logs/`, tune files/notes →
`../data/tunes/`. Nested `Aron/Tune.zip` was a duplicate bundle of the same ROMs.

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

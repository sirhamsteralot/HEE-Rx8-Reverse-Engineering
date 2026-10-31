# input/ — raw intake (never committed)

Drop zone for raw, unvetted material related to the HEE RX-8 effort:

- firmware dumps / `.bin` files before they are verified and promoted
- prior efforts and notes from other people
- cloned third-party git repositories and source trees
- reference downloads (manuals, tools, datasets)

## Rules

- **Nothing inside `input/` is committed to git** (see `../.gitignore`: `input/*` is
  ignored, only this README is tracked). This keeps third-party code, arbitrary
  binaries, and license-unclear material out of the repo.
- Nested git clones are fine here — they stay untracked.
- Treat everything here as untrusted input: verify hashes, provenance, and licensing
  before relying on it.

## Promotion path

When something in `input/` proves useful, don't reference it from tracked files —
copy/promote it into the proper home with provenance:

| Material | Goes to |
|---|---|
| Verified firmware dump | `binaries/` + row in `binaries/manifest.csv` |
| Useful code from another project | summarized/ported into `reverse-engineered/` with attribution in the investigation doc |
| External doc / link | `docs/references/` (URL + access date) |
| Extracted tables/strings | `data/` with source hash + address range |
| Reusable script | `utilities/scripts/` |

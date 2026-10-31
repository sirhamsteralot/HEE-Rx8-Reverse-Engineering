# binaries/

Original, untouched firmware dumps and binary artifacts from the HEE target
(Mazda RX-8). Nothing in this folder is ever edited in place.

## Rules

- One file per acquisition. Name: `<source>-<version>-<date>.<ext>`,
  e.g. `ecu-pcm-v2-2026-11-02.bin`.
- Every file must have a row in `manifest.csv`:
  `filename,size_bytes,sha256,source,acquired_with,date`
- Regenerate/verify the manifest:
  - `python ../utilities/scripts/hash_binaries.py` (writes `manifest.csv`)
  - `python ../utilities/scripts/hash_binaries.py --check` (verifies only)
- Files over ~5 MB go through Git LFS (see `../.gitattributes`). Anything much
  larger: keep it out of git and store only its SHA-256 in the manifest.
- If a dump contains personal data (e.g. a VIN), redact it from any *derived*
  file you commit and note the redaction in the investigation doc.

## manifest.csv

Committed placeholder below; the script rewrites it. Keep the header row.

# data/tunes/

Third-party tune artifacts recovered alongside the ROM dumps (context for the
tuned ROMs in `binaries/dumps/`).

## Layout

- `nr666p/` — VersaTuner `.vtune` containers (Streetport NR666P v1.31 old / v1.34 /
  v1.35). Per the RX8Club thread these are **encrypted** and only exist decrypted
  in flash — keep as opaque reference, do not try to parse as ROM.
- `aron/` — Aron's notes: `README.txt` (Dutch: which bin is the original ECU read,
  which is stock, which is the streetport tune to flash) and RomRaider 3D-table
  pastes (`paste1.txt`/`paste2.txt`, a lambda ≈1.0 Selection3D table).

## Rules

- Tune files are inputs/context, never executed or flashed from this repo.
- Correlate tuned ROMs vs their stock base by byte-diff (see ROADMAP Phase 2);
  record changed address ranges in the investigation doc, not here.

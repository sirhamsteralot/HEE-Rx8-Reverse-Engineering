# data/tunes/

Third-party tune artifacts kept as opaque reference (context only). User-tuned
ROM dumps are not retained in this repo — only factory ROMs (see
[`binaries/README.md`](../binaries/README.md)).

## Layout

- `nr666p/` — VersaTuner `.vtune` containers (NR666P v1.31 old / v1.34 / v1.35; the
  filenames carry the tune brand). Per the RX8Club thread these are **encrypted**
  and only exist decrypted in flash — keep as opaque reference, do not try to
  parse as ROM.

## Rules

- Tune files are inputs/context, never executed or flashed from this repo.

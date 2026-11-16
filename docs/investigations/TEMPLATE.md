# Investigation: <topic>

- **Date started:** YYYY-MM-DD
- **Author:** <name>
- **Status:** open / in-progress / done
- **Placement:** subsystem/logic reports whose logic is shared across ROM bins
  (assumed until proven otherwise) go at the `docs/investigations/` root,
  written against the reference ROM `60E15120_N3J1E`; ROM-specific findings go
  in `docs/investigations/<rom-id>/` and are linked from the root report — see
  [README.md](README.md)
- **Related binaries:** see `binaries/manifest.csv` (list SHA-256 prefixes used)
- **Related code:** paths under `reverse-engineered/` with addresses

## Goal

What question are we answering? (e.g. "How does the ECU compute injector pulse width
at cold start?")

## Method

Tools, approach, steps taken (disassembler, scripts, bench captures, comparison runs).

## Findings

Numbered, each tied to evidence. Reference original addresses, e.g.:

1. `sub_08001234` reads the coolant-temp ADC channel and scales it by ...
2. ...

## Evidence

- Hashes of binaries used, log excerpts, captures, test outputs (link or inline).

## Open questions

- ...

## Next steps

- ...

# references/

External reference material and provenance for third-party sources.

## PDFs (primary reference sources — cite by table/section in reports)

| File | What it is | Use it for | Trust caveats |
|---|---|---|---|
| `Sh7055h.pdf` | Renesas **SH7055F hardware manual** (ADE 602-155B) | Chip-level truth: register map, Tables 1.2/1.3 pin functions & package pin numbers, PFC/port control, ATU-II channel→pin mapping | Vendor document — authoritative for the silicon |
| `13Electrical.pdf` | Original RX-8 electrical wiring book (copy-protected; pages are images) — **ground truth for the RX-8 electrical systems** | Underlying circuit diagrams; source for all derived pinout/colour data | Text extraction yields mostly headers — read via renders; treat as image source |

Derived from `13Electrical.pdf` (regenerate + re-diff, don't edit in place): the
Series-1 PCM connector pinout now lives as text at
`../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md` (the earlier v3 PDF was
removed). It has **no chip-pin numbers** — package-pin ↔ connector-terminal is board
routing, unresolved. Honour its markers: unmarked = confirmed, `*` single-source,
`†` conflict, `³` high-power only, `–` unread.

Rule: firmware dataflow comes from the ROM; physical pin/terminal associations from
these documents; the two meet only at the SH7055F package pin. Never assert a
package-pin ↔ connector-terminal link from the pinout alone.

## Upstream repositories (git submodules — read-only context)

Tracked as submodules under `submodules/` (see `.gitmodules`); fetch with
`git submodule update --init --recursive`. Never edit or commit inside them —
cite files by path + upstream commit hash instead. These are the canonical home
for their content; our repo references them rather than duplicating files:

- `submodules/Mazda_RX8_PCM_ReverseEngineering` — github.com/equinox311/Mazda_RX8_PCM_ReverseEngineering,
  pinned at `492193ba8548869b91915be55133d85ab7a8722a`:
  `Stock_ROMs/` (10 stock ROMs — referenced from `binaries/README.md`),
  `Data_binaries/` (RAM/EEPROM/IC captures), `Ghidra_Archives/` (`.gar`),
  `Utilities/` (upstream patcher scripts)
- `submodules/RX8Defs` — pinned at `1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc`:
  upstream RomRaider/ECUFlash XML definitions. Our `data/definitions/` copies were
  taken from specific upstream commits (cited in
  `docs/investigations/60E15120_N3J1E/defs-merge/`) and may differ from the pinned
  HEAD — that is intentional.
- `submodules/RX8Defs` — github.com/equinox311/RX8Defs: upstream RomRaider ECU +
  logger XML definitions (promoted copies in `data/definitions/romraider/upstream-rx8defs/`);
  commit hashes are cited as merge provenance — never rewrite that history
- `submodules/Rx8Man` — github.com/Rx8Man/Rx8Man, pinned at
  `50f905bc271e918a00ce0eda96e6414c220886e5`: PCM reflash tool for Tactrix
  (never flash without bench validation)

Related but not submoduled (not git repos in the intake, URL only):

- RomRaider (Java) — https://www.romraider.com/ / github.com/RomRaider/RomRaider
- Renesas SH-2E/SH7055S hardware manual:
  https://www.renesas.com/en/document/mah/sh-2e-sh7055s-hardware-manual

## Prior-effort workspace docs

- `prior-effort-agents.md` — the previous workspace's AGENTS.md, preserved for
  provenance; its rules are distilled into this repo's root `AGENTS.md`.
- `../learnings.md` — the previous sessions' know-how log.

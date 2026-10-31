# references/

External reference material and provenance for third-party sources.

## PDFs (primary reference sources — cite by table/section in reports)

| File | What it is | Use it for | Trust caveats |
|---|---|---|---|
| `Sh7055h.pdf` | Renesas **SH7055F hardware manual** (ADE 602-155B) | Chip-level truth: register map, Tables 1.2/1.3 pin functions & package pin numbers, PFC/port control, ATU-II channel→pin mapping | Vendor document — authoritative for the silicon |
| `mazda-rx-8-pcm-pinout-series-1.pdf` | Series-1 PCM connector pinout compiled from the Mazda FSM terminal table + `13Electrical.pdf` wire colours | PCM connector terminal → signal/component + wire colour | Generated from the wiring book; **no chip-pin numbers** (package-pin ↔ terminal is board routing, unresolved). Honour its markers: unmarked = confirmed, `*` single-source, `†` conflict, `³` high-power only, `–` unread |
| `13Electrical.pdf` | Original RX-8 electrical wiring book (copy-protected; pages are images) | Circuit diagrams behind the pinout | Text extraction yields mostly headers — read via renders; treat as image source |

Rule: firmware dataflow comes from the ROM; physical pin/terminal associations from
these documents; the two meet only at the SH7055F package pin. Never assert a
package-pin ↔ connector-terminal link from the pinout alone.

## Upstream repositories (git submodules — read-only context)

Tracked as submodules under `submodules/` (see `.gitmodules`); fetch with
`git submodule update --init --recursive`. Never edit or commit inside them —
cite files by path + upstream commit hash instead:

- `submodules/Mazda_RX8_PCM_ReverseEngineering` — github.com/equinox311/Mazda_RX8_PCM_ReverseEngineering:
  stock ROMs, data binaries, Ghidra archives, utilities (promoted copies live in
  `binaries/`, `reverse-engineered/disassembly/archives/`, `utilities/scripts/patchers/`)
- `submodules/RX8Defs` — github.com/equinox311/RX8Defs: upstream RomRaider ECU +
  logger XML definitions (promoted copies in `data/definitions/romraider/upstream-rx8defs/`);
  commit hashes are cited as merge provenance — never rewrite that history
- `submodules/Rx8Man` — github.com/Rx8Man/Rx8Man: PCM reflash tool for Tactrix
  (never flash without bench validation)

Related but not submoduled (not git repos in the intake, URL only):

- RomRaider (Java) — https://www.romraider.com/ / github.com/RomRaider/RomRaider
- Renesas SH-2E/SH7055S hardware manual:
  https://www.renesas.com/en/document/mah/sh-2e-sh7055s-hardware-manual

## Prior-effort workspace docs

- `prior-effort-agents.md` — the previous workspace's AGENTS.md, preserved for
  provenance; its rules are distilled into this repo's root `AGENTS.md`.
- `../learnings.md` — the previous sessions' know-how log.

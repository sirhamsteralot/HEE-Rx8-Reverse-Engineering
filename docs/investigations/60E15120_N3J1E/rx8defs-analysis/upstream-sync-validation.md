# Upstream submodule sync validation — RX8Defs `01de56b`

Record of pulling all three upstream submodules to their latest upstream
commits and validating our findings and ECU definitions against what changed.
Static-analysis workspace only: no ROM bytes were touched (AGENTS.md rule 2),
`submodules/` stays read-only context (rule 4b).

## 1. What moved

| Submodule | Old pin | New pin | Verdict |
|-----------|---------|---------|---------|
| `submodules/RX8Defs` (equinox311/RX8Defs) | `1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc` | `01de56be61b807f58b0b81820d4d2478c16ecc16` (master, 2026-11-02) | **updated** |
| `submodules/Mazda_RX8_PCM_ReverseEngineering` | `492193ba8548869b91915be55133d85ab7a8722a` | same — verified against `git ls-remote` (master HEAD identical) | already latest |
| `submodules/Rx8Man` | `50f905bc271e918a00ce0eda96e6414c220886e5` | same — HEAD = main = tags 1.05/1.20/1.21 all point at `50f905b` | already latest |

`RX8Defs` moved by two commits: `d95b0be` ("Updated faults for clarity on
operation, as well as turned them into switch cals. Added another ROM cal ID
for ease of def finding. Removed some commented out defs", 2026-11-02) and
`01de56b` (README only). Only `RomRaider/rx8_defs.xml` changed content
(blob `29afd000…` → `c747d084…`); `RomRaider/logger_rx8_defs.xml`
(`ba8edef8…`), `ECUFlash/60E0G500.xml` (`c4a3c37e…`) and
`ECUFlash/RX8BASE.xml` (`05a7943e…`) are blob-identical at the new pin.

All commit hashes cited anywhere in our docs (`ff5ab4f`, `944062e`, `251f54f`,
`607d1a3`, `aaac6f3`, `1b3aea2` itself) still resolve in the submodule history
(`git cat-file -e`), and every cited submodule path exists at the new pin.
`Stock_ROMs/` still holds the same 10 ROMs, so every
`submodules/Mazda_RX8_PCM_ReverseEngineering/…` reference is unaffected.

## 2. Upstream delta inventory (`rx8_defs.xml`, `1b3aea2..01de56b`)

Parsed both revisions block-by-block (`<rom>`/`<romid>/<xmlid>` inventory +
per-table `(storageaddress, type, storagetype, size, sizey, category)`
signature diff):

- **No `<rom>` block added or removed**; base chains unchanged; no table
  storage address changed anywhere.
- **RX8Base: 369 DTC tables reworked** (1051 → 1051 tables, names unchanged):
  - 123 × `DTC xxxx Enable/Disable #1`: `1D uint8 size=1` → `Switch` with
    `Enabled=01` / `Disabled=00`, category `DTCs` → **`DTC - MIL Illuminate`**
  - 123 × `#2`: same conversion, category → **`DTC - OBD Report`**
  - 123 × `#3`: unchanged `1D uint8`, category `DTCs` → **`DTC - Unknown`**
- **60E0G500 block**: additional `<romid>` `N3ZGEC` (internalidaddress
  `6CE46`) next to `N3ZHEC` — the "another ROM cal ID" from the commit message.
  Block table count unchanged (814 top-level tables).
- **G-ROM_FLEX**: commented-out Flex Fuel tables removed. Consistent with our
  stock-only policy: `extend_defs_all_roms.py` strips the `Flex Fuel` category
  from every per-ROM def anyway, so nothing to re-strip.
- Per-ROM blocks (incl. 60E15120) are otherwise untouched: the 60E15120 block
  still binds only the `#1` DTC bank (121 `storageaddress` overrides,
  `0x7E678`–`0x7E6F0`); `#2`/`#3` remain upstream placeholders.

## 3. Findings cross-check — DTC model

Upstream's new categorization matches what
[`../dtc_control_report.md`](../dtc_control_report.md) verified against the
60E15120 ROM at binary level:

| Upstream (new) | Our finding (60E15120_N3J1E) | Match |
|----------------|------------------------------|-------|
| `#1` = "MIL Illuminate" switch | enable#1 bank `0x7e678`+slot gates MIL (`0x5a130`) and aging; per-ROM defs bind exactly this bank (`0x7E678`–`0x7E6F0`) | yes |
| `#2` = "OBD Report" switch | enable#2 bank `0x7e704`+slot gates the Mode 03 list and freeze frame | yes |
| `#3` = "Unknown", still plain 1D | enable#3 bank `0x7e790`+slot is a **feature bitmask** (0x02/0x04/0x08/0x10/0x20), not on/off — upstream leaving it a raw 1D is consistent with that | yes |

No conflict with any report; the upstream labels are coarser than ours but in
agreement. The `N3ZGEC` cal ID was already present in our
`per-rom/60E0G500_N3ZHEC.xml` (cal-string provenance from the ROM itself), so
no label change was needed there.

## 4. Definitions validation — regeneration at the new pin

Re-ran the re-runnable pipeline pass from the repo root:

```sh
git submodule update --remote
python utilities/scripts/defs-merge/extend_defs_all_roms.py
```

Result (`git diff` of `data/definitions/`):

- 8 of 9 per-ROM defs changed (`60E15120_N3J1E.xml` is unchanged — see below);
  per changed def the delta is **exactly** the 369 DTC tables from §2 plus the
  provenance comment pin (`1b3aea2…` → `01de56b…`): **0 tables added, 0
  removed, 0 name changes, 0 `<description>` changes** — all curated table
  labels from the label map re-applied cleanly on regeneration.
- `coverage.json` regenerated: `pinned_commit` `01de56b…`,
  `romraider_rx8_defs_last_change` = `d95b0be … 2026-11-02`, `dedupe_d8`
  pinned blob re-verified (`c747d084…`).
- `per-rom/60E15120_N3J1E.xml` and `rx8defs-merged-60E15120.xml` still carry the
  old 1D DTC tables because the reviewed 60E15120 merge is built against
  upstream `ff5ab4f` ("do not mix" note in
  [`../../../../data/definitions/README.md`](../../../../data/definitions/README.md)).
  Ingesting the new DTC switch form there is open follow-up in
  [`../../../../ROADMAP.md`](../../../../ROADMAP.md) (group C open work).

## 5. Validation results (all run from the repo root on the synced tree)

| Check | Result |
|-------|--------|
| `python utilities/scripts/hash_binaries.py --check` | manifest OK — no binary touched |
| `validate_export.py` | exit 0 — ROM SHA-256 verified, 3355 function files, 337184 instruction bytes verified |
| `validate_reports.py` | PASS (`failures: []`) — run with `PYTHONUTF8=1` on Windows, the script's default-locale read trips on UTF-8 report text |
| `verify_claims.py` | PASS (`failures: []`), same `PYTHONUTF8=1` note |
| `verify_readability.py` | exit 0, 3355 function bodies consistent |
| `verify_math_units.py` | verified 16 shift pairs, 10007 fixed-point boundary/random cases, 70 constant pairs |
| `python -m pytest tests/` | 187 passed |
| Pin citations in docs | `1b3aea2…` → `01de56b…` updated in [`data/definitions/README.md`](../../../../data/definitions/README.md), `data/definitions/coverage.json`, [`docs/references/README.md`](../../../references/README.md), [`../cross_ecu/cross_rom_defs_coverage.md`](../cross_ecu/cross_rom_defs_coverage.md), [`../../60E0G500_N3ZHEC/defs-merge/README.md`](../../60E0G500_N3ZHEC/defs-merge/README.md) + `validation.json`; historical citations (`ff5ab4f`, `251f54f`, …) left as-is, they still resolve |

## 6. Follow-up

The reviewed merged 60E15120 def (base `ff5ab4f`) does not yet carry the
upstream `01de56b` DTC switch model; only the 8 upstream-block per-ROM defs do.
Rebasing or splicing that base is tracked as open work in
[`../../../../ROADMAP.md`](../../../../ROADMAP.md) (group C). No other
upstream delta requires action: logger/ECUFlash XMLs are unchanged, no new ROMs
appeared upstream, and Rx8Man / Mazda_RX8_PCM_ReverseEngineering were already
at their latest commits.

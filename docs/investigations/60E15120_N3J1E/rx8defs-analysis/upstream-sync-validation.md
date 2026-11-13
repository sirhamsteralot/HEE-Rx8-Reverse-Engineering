# Upstream submodule sync validation — RX8Defs `39d98a0`, MRP `b243b35`

Record of pulling all three upstream submodules to their latest upstream
commits and validating our findings and ECU definitions against what changed.
Static-analysis workspace only: no ROM bytes were touched (AGENTS.md rule 2),
`submodules/` stays read-only context (rule 4b).

## 1. What moved

| Submodule | Old pin | New pin | Verdict |
|-----------|---------|---------|---------|
| `submodules/RX8Defs` (equinox311/RX8Defs) | `1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc` | `39d98a0a87faa1ea3225f7122a1ac2b9d620ff9f` (master, 2026-11-12) | **updated** |
| `submodules/Mazda_RX8_PCM_ReverseEngineering` | `492193ba8548869b91915be55133d85ab7a8722a` | `b243b355002f591f97631708af081d89e935b6c9` (master, 2026-11-12) | **updated** |
| `submodules/Rx8Man` | `50f905bc271e918a00ce0eda96e6414c220886e5` | same — HEAD = main = tags 1.05/1.20/1.21 all point at `50f905b` (verified via `git ls-remote`) | already latest |

RX8Defs moved by three commits: `d95b0be` (2026-11-02, DTC rework — see §2),
`01de56b` (README only) and `39d98a0` (2026-11-12, immobilizer fixes — see §3).
Only `RomRaider/rx8_defs.xml` changed content (blob `29afd000…` → `82e5724d…`);
`RomRaider/logger_rx8_defs.xml` (`ba8edef8…`), `ECUFlash/60E0G500.xml`
(`c4a3c37e…`) and `ECUFlash/RX8BASE.xml` (`05a7943e…`) are blob-identical at
the new pin. MRP changed only `Utilities/G_ROM_ImmoDefWriter.py` (+ its `.zip`)
in `b243b35` ("updated immobilizer script to correct memory issues with some
patches") — the same immobilizer fix as RX8Defs `39d98a0`, on the script side.
`Stock_ROMs/` and `Data_binaries/` are unchanged (no new ROMs or captures).

All commit hashes cited anywhere in our docs (`ff5ab4f`, `944062e`, `251f54f`,
`607d1a3`, `aaac6f3`, `1b3aea2` itself) still resolve in the submodule history
(`git cat-file -e`), and every cited submodule path exists at the new pins.

## 2. Upstream delta: DTC switch rework (`d95b0be`)

Parsed both revisions block-by-block (`<rom>`/`<romid>/<xmlid>` inventory +
per-table `(storageaddress, type, storagetype, size, sizey, category)`
signature diff):

- No `<rom>` block added or removed (at `01de56b`); base chains unchanged; no
  table storage address changed.
- **RX8Base: 369 DTC tables reworked** (1051 → 1051 tables, names unchanged):
  123 × `DTC xxxx Enable/Disable #1`: `1D uint8 size=1` → `Switch`
  (`Enabled=01`/`Disabled=00`), category `DTCs` → **`DTC - MIL Illuminate`**;
  123 × `#2` same conversion → **`DTC - OBD Report`**; 123 × `#3` unchanged
  `1D uint8`, category → **`DTC - Unknown`**.
- **60E0G500 block**: additional `<romid>` `N3ZGEC` (internalidaddress
  `6CE46`) next to `N3ZHEC`; block table count unchanged (814).
- **G-ROM_FLEX**: commented-out Flex Fuel tables removed — consistent with our
  stock-only policy (`extend_defs_all_roms.py` strips the `Flex Fuel` category
  from every per-ROM def anyway).

### Findings cross-check — DTC model

Upstream's new categorization matches what
[`../dtc_control_report.md`](../dtc_control_report.md) verified against the
60E15120 ROM at binary level:

| Upstream (new) | Our finding (60E15120_N3J1E) | Match |
|----------------|------------------------------|-------|
| `#1` = "MIL Illuminate" switch | enable#1 bank `0x7e678`+slot gates MIL (`0x5a130`) and aging; per-ROM defs bind exactly this bank (`0x7E678`–`0x7E6F0`) | yes |
| `#2` = "OBD Report" switch | enable#2 bank `0x7e704`+slot gates the Mode 03 list and freeze frame | yes |
| `#3` = "Unknown", still plain 1D | enable#3 bank `0x7e790`+slot is a **feature bitmask** (0x02/0x04/0x08/0x10/0x20), not on/off — upstream leaving it a raw 1D is consistent | yes |

No conflict with any report. `N3ZGEC` was already present in our
`per-rom/60E0G500_N3ZHEC.xml` (cal-string provenance from the ROM itself).

## 3. Upstream delta: immobilizer patch addresses (`39d98a0`)

Block-level diff `01de56b..39d98a0` on `rx8_defs.xml`:

- **Per-block `Immobilizer Disable` storage addresses changed** (the "fixed
  otherwise incorrect patch addresses"):
  - 60E15120 block: without-RKE `0x34da8` → `0x34b10`, with-RKE `0x351f4` → `0x34f5c`
  - 60E1D400 block: `0x755e` → `0x35d90`, `0x79aa` → `0x361dc`
  - 60E32000 block: `0x371d8` → `0x37278`, `0x37624` → `0x376c4`
  - 60E0FC00 / 60E1B900: hex-case-only (`0x3567C`→`0x3567c`, `0x354C8`→`0x354c8`)
  - G-ROM_FLEX: immobilizer tables removed
  - **60E1B900 block `<xmlid>` blanked** (internalidstring still `60E1B900`)
- **Rename**: `Table 3D - UNKNOWN_CL` → **`Closed Loop Fueling Base`**
  (RX8Base template + 60E09L0N/60E0FC00/G-ROM_FLEX overrides; same addresses,
  e.g. `0x70b3c`); 12 RX8Base tables re-categorized `Fuel Target (Closed Loop)`
  → `Fuel Injection - Closed Loop`.

### Binary-level verification of the new addresses (AGENTS.md rule 7)

Searched every dumped ROM (own dumps + upstream `Stock_ROMs/`) for the
immobilizer start patterns used by upstream's `G_ROM_ImmoDefWriter.py`
(`B56E000960D0600C88008D1100098801` / `B560…` variant), from 0x2000 up. The
def `storageaddress` is the pattern offset; with-RKE = offset + 0x44c
(`w_rke_offset = 0xf7 + 0x355`):

| ROM (fw id) | pattern offset | upstream before | upstream now | verdict |
|-------------|----------------|-----------------|--------------|---------|
| 60E15120_N3J1E | `0x34b10` | `0x34da8` | `0x34b10` / `0x34f5c` | **new correct**, old was wrong |
| 60E1D400 | `0x35d90` | `0x755e` | `0x35d90` / `0x361dc` | **new correct**, old was wrong |
| 60E32000_N3M5E | `0x37278` | `0x371d8` | `0x37278` / `0x376c4` | new correct for N3M5E |
| 60E32000_N3N5EB | `0x371d8` | `0x371d8` | `0x37278` / `0x376c4` | **old was correct for N3N5EB — new address is wrong for this ROM** (discrepancy D13) |
| 60E1B900 | `0x354c8` | `0x354C8` | `0x354c8` | case-only, same address |
| 60E0FC00 / 60E0FB00 | `0x35230` | (via G-ROM_FLEX `0x35230`, with-RKE `0x3567c`) | `0x3567c` case-only | unchanged |
| 60E0G500_N3ZHEC | `0x35af8` | — | — | no block override either side |
| 60E0E500 / 60E0E700_N3YLEE | `0x3565c` / `0x357c8` (B560 variant) | — | — | no block override either side |
| 60E1C500_N3J6EB | `0x358fc` | — | — | block commented out upstream (`251f54f`) |

So upstream `39d98a0` fixes real bugs (60E15120, 60E1D400 were pointing into
the wrong code region) but the single 60E32000 block now matches only the
N3M5E variant — recorded as discrepancy **D13** in
[`../../../../ROADMAP.md`](../../../../ROADMAP.md). Our reviewed merged
60E15120 def still carries the pre-fix `0x34da8`/`0x351f4`, now ROM-proven
wrong; splicing the corrected addresses in is part of ROADMAP C item 22.

## 4. Definitions validation — regeneration at the new pins

Re-ran the re-runnable pipeline pass from the repo root:

```sh
git submodule update --remote
python utilities/scripts/defs-merge/extend_defs_all_roms.py
```

- 60E1B900: upstream blanked the block's `<xmlid>`, so
  `extend_defs_all_roms.py` now falls back to `<internalidstring>` in
  `blocks()` and relaxes the `validate_block` xmlid assertion — the
  `per-rom/60E1B900.xml` def still generates (851 tables, status OK).
- Delta vs the previous pin in the 8 upstream-block per-ROM defs is exactly:
  the `Table 3D - UNKNOWN_CL` → `Closed Loop Fueling Base` rename, 3–12
  category renames to `Fuel Injection - Closed Loop` per ROM, and the
  immobilizer address changes from §3 (case-only for 60E0FC00/60E1B900). Zero
  other table changes; curated labels re-applied cleanly (relabel matches by
  ROM data address, not by upstream table name, so the upstream rename does
  not disturb our label map). `per-rom/60E15120_N3J1E.xml` unchanged (reviewed
  merged block, base `ff5ab4f`).
- `coverage.json` regenerated: `pinned_commit` `39d98a0…`, last change
  `39d98a0 … 2026-11-12`, `dedupe_d8` pinned blob re-verified (`82e5724d…`).
- The 12 RX8Base tables re-categorized to `Fuel Injection - Closed Loop`
  upstream: 9 curated label-map entries still name the old
  `Fuel Target (Closed Loop)` category, so marked tables in the per-ROM defs
  keep it until the merged 60E15120 def is rebased/spliced (ROADMAP C item 22);
  `tests/test_defs_relabel.py` accepts the old name via an explicit
  upstream-rename alias so the "no invented categories" invariant still holds.
- MRP `b243b35` touches only the upstream immobilizer script; our
  `utilities/scripts/patchers/` do not wrap `G_ROM_ImmoDefWriter.py`, nothing
  to change on our side. Pin citations updated in `docs/references/README.md`
  and [`binaries/README.md`](../../../../binaries/README.md).

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
| Pin citations in docs | `1b3aea2…` → `39d98a0…` (RX8Defs) and `492193b…` → `b243b35…` (MRP) updated in `data/definitions/README.md`, `coverage.json`, [`docs/references/README.md`](../../../references/README.md), [`binaries/README.md`](../../../../binaries/README.md), [`../cross_ecu/cross_rom_defs_coverage.md`](../cross_ecu/cross_rom_defs_coverage.md), [`../../60E0G500_N3ZHEC/defs-merge/README.md`](../../60E0G500_N3ZHEC/defs-merge/README.md) + `validation.json`; historical citations (`ff5ab4f`, `251f54f`, …) left as-is, they still resolve |

## 6. Follow-up

- The reviewed merged 60E15120 def (base `ff5ab4f`) and therefore
  `per-rom/60E15120_N3J1E.xml` **now carry the upstream changes**, spliced (not
  rebased — the merged RX8Base keeps its local reviewed content): the `d95b0be`
  DTC switch form (#1/#2 `Switch` Enabled=01/Disabled=00 under
  "DTC - MIL Illuminate" / "DTC - OBD Report", #3 raw 1D under
  "DTC - Unknown", local P-code names kept) and the corrected 60E15120
  immobilizer addresses `0x34b10`/`0x34f5c` with the regenerated patch blob.
  Splice pass:
  [`utilities/scripts/defs-merge/splice_upstream_dtc_immo.py`](../../../../utilities/scripts/defs-merge/splice_upstream_dtc_immo.py)
  (pass log
  [defs-merge/upstream_splice_39d98a0.json](../defs-merge/upstream_splice_39d98a0.json));
  the pass re-verifies the immo start pattern and the switch "off" blob against
  the ROM bytes on every run. `repair_dtc_tables()` in `extend_defs_all_roms.py`
  emits the same Switch form for every per-ROM def. Tests:
  `tests/test_defs_upstream_sync.py`; pipeline validators + full pytest green.
  The remaining upstream renames (Table 3D name, "Fuel Injection - Closed
  Loop" categories) are folded in together with the label-map category update.
- **ROADMAP discrepancy D13** — the 60E32000 upstream block's immobilizer
  addresses now match only N3M5E; for N3N5EB the ROM pattern sits at
  `0x371d8`/`0x37624`, so `per-rom/60E32000_N3N5EB.xml` inherits an address
  that is wrong for that ROM. A per-ROM immo-address repair derived from the
  ROM pattern (same approach as `repair_dtc_tables`) would close this.

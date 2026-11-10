# DTC authoring — evidence notes — 60E15120_N3J1E

Evidence for [`../../dtc_authoring_report.md`](../../dtc_authoring_report.md)
(the authoring checklist: which tables/args/slots a new DTC must touch). The full
DTC chain (raise → state machine → MIL → E2RAM persistence → scanner readout) is
documented in [`../../dtc_control_report.md`](../../dtc_control_report.md) §1–§2b;
this folder's dumps back the checklist addresses and the persistence lists.

## What was verified, and how

All checks run against the raw ROM
(`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`,
SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
matches the hash recorded in every report header) using the re-runnable dump
script [`dump_dtc_authoring_tables.py`](dump_dtc_authoring_tables.py); its full
output is in [`tables_dump.txt`](tables_dump.txt).

- **DTC tables byte-exact:** arg→slot 0x7df42, code table 0x7e560, prefix 0x7e55a,
  enables 0x7e678/0x7e704/0x7e790, type 0x7e32a, conf mask 0x7e81c, status mask
  0x7e934, monitor-source mask 0x7e29e, related records 0x7e06c, UDS service table
  0x5eb40 (29 × 12-byte records; 0x19/0x1a absent).
- **Free capacity:** slots 0x79–0x8b hold code 0xffff with enable#1=#2=0; 11 slots
  with real codes ship disabled (see tables_dump.txt).
- **Literal-pool anchors:** mov.l pool words in ROM point at the tables, e.g.
  0x5ff1c / 0x60134 / 0x6027c / 0x602d8 / 0x6122c / 0x66c38 → 0x7df42;
  0x60928 / 0x669f4 → 0x7e560; 0x66bfc → 0x7e934; 0x5f9e8 → 0x7e790;
  0x5f9ec → 0x7e81c; 0x5fc10 → 0x7e29e. Cross-checked against
  `reverse-engineered/disassembly/60E15120_N3J1E/non_instruction_ranges_classified.tsv`
  (pool ranges 0x5f9d6…, 0x5fc08…, 0x5ff12…, 0x6012a…, 0x602d0…, 0x66bf8…).
  No pool word references 0x7e05a (the arg-table tail) — treated as unused.
- **Disassembly re-read:** 0x5fe20 indexes 0x7df42 with arg*2 (extu.w + shll,
  `mov.w @(r0,r14)` at 0x5fe40, pool 0x5ff1c); 0x60062 dispatches on mode r5
  (cmp 2/4/1/0 at 0x60086–0x6009a) and reads the type byte via pool 0x60138;
  0x601cc stores `0xffffd570[slot]=1` (pool 0x60274) and first code at 0xffffd3c0
  (pool 0x60278, `or r6` when zero) for mode 1 only.
- **Callgraph counts** (`reverse-engineered/decompiled/60E15120_N3J1E/callgraph.tsv`):
  0x5fd38 = 71 callers; 0x66a00 = 80 callers; edge 0x64ba → 0x1150e present
  (task[9] batch carries the E2RAM save via thunk → 0x236cc);
  0x1102a → 0x5a130 / 0x612ee; 0x54d90 → 0x55278.
- **Charging example chain:** arg 0x7b → u16 at 0x7df42+0xf6 = 0x71 → code u16 at
  0x7e560+0xe2 = 0x2502 (P2502); 0x545bc calls `0x5fd38(0x7b, b5b1==0 ? 2 : 1)`.
- **Persistence lists:** 0x242ae collect = 18 `ref_getFaultStatus__` calls
  (args 0x13/0x14, 0x21/0x22, 0x42, 0x47, 0x64, 0x5b/0x5c, 0x5d, 0x65, 0x6a, 0x83,
  0x4f, 0x5f, 0x60, 0x61, 0x6b) writing staging 0xffffb4dc–0xffffb4eb plus
  conditionals 0xffffb4ea/0xffffb4eb/0xffffb51c; 0x23f4e replay = 38 `0x5fd38(arg,
  1|2)` calls for args 0x13, 0x14, 0x21, 0x22, 0x42, 0x47, 0x4f, 0x5b, 0x5c, 0x5d,
  0x5f, 0x60, 0x61, 0x64, 0x65, 0x6a, 0x6b, 0x83, 0x84 driven by flags
  0xffffb4ec–0xffffb51b; encode 0x244bc packs collect bytes into 0xffffb459–
  0xffffb45d; decode 0x23844 unpacks raw 0xffffb48a–0xffffb490 (via 0x24b00) into
  the same flag range. Charging args 0x7b/0x7c/0x7d are in **neither** list →
  P2502/2503/2504 do not survive key-off.
- **UDS 0x18:** service record 0x5ec0c (svc 0x18, handler 0x57db0, param 5);
  sub-function 1 with status byte 3 → 0x58168 sets 0xffffd228 = 1/2 (report
  selector). 0x19/0x1a fall through to the 0xff default record (0x5ec90 → 0x6689a).

## Sceptical notes

- The save/load offset asymmetry of the packed fault field (save writes block
  bytes 0xffffb459–0xffffb45d from base 0xffffb440; load decodes read-staging bytes
  0xffffb48a–0xffffb490 from base 0xffffb478) was **not** reconciled at device-frame
  level; the report states both RAM addresses and does not claim a device offset.
- The arg→flag-byte map is from the decompiled replay (0x23f4e); the bit-level masks
  inside 0x244bc/0x23844 were read but not re-derived instruction by instruction.
- Dynamic evidence for the reporting half:
  [`../dtc_control/dynamic_validation_log.txt`](../dtc_control/dynamic_validation_log.txt).

## Validation

See `validation.json` in this folder (pipeline validators + pytest results).

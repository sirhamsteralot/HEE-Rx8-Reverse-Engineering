# Targeted static review: E2RAM device layer (parameter read/write + SCI4 protocol)

Scope: the inherited `ref_getDataFromE2RAM` 0x3599c /
`ref_writeToE2RAMArea_INDEX_ADDR_LEN` 0x37ea4 layer and the device primitives of
60E15120_N3J1E (RX-8 PCM, SH7055F), read from the canonical export
(`decompiled/`), the disassembly and the raw ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, untouched).
Root report: [`../../e2ram_device_layer_report.md`](../../e2ram_device_layer_report.md);
record: `data/labels/60E15120_N3J1E/e2ram_device_labels.json`.
Companion (not re-derived here): the 28-u16 block codec in
[`../../e2ram_nv_storage_report.md`](../../e2ram_nv_storage_report.md).

## 1. Device protocol — SCI4 + CS/busy lines

Register names from symbols.tsv: SCI_SCR4_B 0xfffff022, SCI_TDR4_B 0xfffff023,
SCI_SSR4_B 0xfffff024, SCI_RDR4_B 0xfffff025; PFDR_W 0xfffff74e (bit 0x400 = CS),
PBDR_W 0xfffff738 (bit 0x800 = busy/status in), PBCRH_W 0xfffff732, PLIR_W
0xfffff75c. (Correction: the decompiled C mislabels 0xfffff74e as PLDR_W;
symbols.tsv says PFDR_W.)

- 0xbf3a `e2ram_cs_port_setup`: PLIR_W &= ~0x200; PBCRH_W &= ~0x30; PBDR_W bit
  0x400 = 0 via 0x4bbc; PFDR_W bit 0x400 = 1 (CS high); PBCRH_W |= 0x10.
  Helper pools 0xc014-0xc028 (0x2054/0x4bbc/0x2064, 0xfdff, 0xffcf).
- 0xbfa0 `sci4_send_bytes(buf, n)`: SCR4 |= 0x20 (TE); per byte wait SSR4 bit
  0x80 (TDRE), TDR4 = byte, SSR4 = b & 0x7f | 0x78; end wait SSR4 bit 0x4, SCR4
  &= 0xb.
- 0xc02c `sci4_read_u16`: PLIR_W |= 0x200; SCR4 |= 0x30 (TE|RE); dummy TDR4=0;
  wait SSR4 bit 0x40 (RDRF); RDR4 -> first byte; second byte likewise.
- 0xbed8 `e2ram_busy_status_read`: PFDR_W bit 0x400 = 1, wait 0x239c
  (sh_busy_wait_count_times_8(1)), read PBDR_W, PFDR_W bit 0x400 = 0; returns
  (val & 0x800) == 0.
- 0xbdfa `e2ram_read_word(addr)`: 0xbf3a, 0xbfa0(addr, 2), 0xc02c, CS down
  (PFDR_W 0x400 = 0 via 0x4bbc); helper pools 0xbecc/0xbed4/0xbed0.
- 0xbe30 `e2ram_send_command2(cmd)`: 0xbf3a, 0xbfa0(cmd, 2), CS down.
- 0xbe5e / 0xbe8c: same with 0xbfa0(cmd, 4).

## 2. Parameter layer (shadow cache)

- Shadow: 0xffffc28e[256] data + 0xffffc38e[256] complement (valid when
  data[i] == ~comp[i]).
- 0x37ef0 `e2ram_cached_byte_read(index, &dest, len)`: mask 0x10 (pool
  0x37f6c = 0x3920); per byte: if shadow valid copy it, else 0xbed8 (pool
  0x37f70) then 0xbdfa (pool 0x37f88) at 0x6000000 + ((index>>1)&0xff)*0x10000
  (base pool 0x37f84 = 0x6000000); even index = high byte of the u16
  (big-endian); update shadow+complement; error flag in r0; tail 0x3934.
- 0x37ea4 `e2ram_shadow_byte_write(index, src, len)`: mask 0x10; per byte
  0xffffc28e[i] = b, 0xffffc38e[i] = ~b (pools 0x37f7c/0x37f80); tail 0x3934.
  Callers (callgraph): 0x279d8, 0x27d06, 0x35a8c, 0x4b668, 0x5d9d8, 0x5e8a4.
- 0x37cd8 `e2ram_bulk_read_into_shadow(start, len)` (inherited ref_E2IntoRAM_):
  double 0xbed8; pages p = start>>1 .. (start+len-1)>>1 (0xffffc492/0xffffc494);
  0xbdfa(0x6000000 + p*0x10000); hi byte -> 0xffffc28e[2p], lo byte ->
  0xffffc28f[2p], complements 0xffffc38e/f. Callers: 0x27b8e, 0x35956, 0x4b5b6,
  0x5b482.
- 0x3599c `e2ram_boot_param_read` (inherited ref_getDataFromE2RAM): 19 calls to
  0x37ef0 (pool 0x35a48), dest cells 0xffffc268-0xffffc282 (pools 0x35a4c-0x35a88,
  classified u32_table 0x35a40-0x35a8b), indexes 0,2,6,10,0xc,0xd,0xe,0xf,0x10,
  0x16,0x18,0x12,0x13,0x14,0x1a,0x1b,0x1c,0x1d,0x1e. Caller 0x349e4 <- 0x1102a (boot).
- 0x35a8c `candidate_e2ram_param_write_dispatch`: id -> (index, &cell, len) via
  0x37ea4 / thunk 0x35d36; 30 calls; pools 0x35b70-0x35b84 (mixed_pool
  0x35b66-0x35b87).
- 0x379e4 `candidate_e2ram_verify_state_machine`: states 0xffffc49c 1-4;
  0xbed8; 0xbe30(0x4c00000) (pools 0x37bd4/0x37bd8); read-back
  0xbdfa(0x6000000 + (byte)0xffffc498*0x10000) vs expected 0xffffc49a; status
  0xffffc4a0-a6. Caller 0x38082.

## 3. Validation

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256, 168,592
instruction bytes, 1,833 exact reference matches), `verify_claims.py`,
`verify_readability.py`, `verify_math_units.py`, `validate_reports.py` — all PASS;
`python -m pytest tests/` 134 passed. Labels applied by
`review_e2ram_labels.py` + `annotate_source_review.py` +
`integrate_reviewed_names.py` (15 function rows, 3 RAM rows; 60 export files
renamed; 3,355 function bodies verified intact).

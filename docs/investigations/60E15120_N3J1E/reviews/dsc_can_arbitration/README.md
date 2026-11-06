# Targeted static review: DSC-related CAN arbitration (0x2a2ae batch + CAN 0x212)

Scope: the inherited `ref_updateDSCRelatedCANStuff__` 0x2a2ae area of
60E15120_N3J1E (RX-8 PCM, SH7055F), read from the canonical export
(`decompiled/`), the disassembly and the raw ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, untouched).
Root report: [`../../dsc_can_arbitration_report.md`](../../dsc_can_arbitration_report.md);
record: `data/labels/60E15120_N3J1E/dsc_can_labels.json`.

## 1. The batch 0x2a2ae (renamed `dsc_can_arbitration_batch`)

15 calls (14 jsr + 1 tail jmp; 13 signal callees + mask/SR helpers 0x3920/0x3934)
under mask 0x10, from task[10] 0x11744. Pool words
in classified u32_table 0x2a3e0-0x2a4f4, read from ROM:

```
0x2a448=0x3920 (mask raise)   0x2a454=0x3934 (ref_setSR, tail)
0x2a468=0x2b314 can212_rx_signal_validity
0x2a46c=0x2b3b8 engine_max_torque_allowed_calc
0x2a470=0x2b496 (desired torque)   0x2a474=0x2b6a4 (mode bit 0x08 of bbde)
0x2a478=0x2b6c2 0x2a47c=0x2b754 0x2a480=0x2b788 0x2a484=0x2b7a6  (mode bits 0x80/0x40/0x20/0x10 of bbf6)
0x2a488=0x2b7c4 (timeout flag)    0x2a48c=0x2b046 (rear wheelspeed avg)
0x2a490=0x2b156 vehicle_moving    0x2a494=0x2b17e 0x2a498=0x2b1aa (LR/RR validity)
```

## 2. CAN 0x212 RX chain

- Mailbox descriptor record at ROM 0x4e21c (16 bytes; buffer field at 0x4e224):
  `00000212 01210700 ffffbbc0 01000000` = ID 0x212, ctrl byte r[6]=0x07 at
  0x4e222 (DLC 7), RAM buffer 0xffffbbc0.
- 0x2b29c `can212_rx_main` (8 calls): copy mailbox via descriptor 0x4e21c; on
  success 0xe038 → 0x2b7e2 → 0x2b816 (0xffffbbc8 = 0xffffbbf2) → 0x2b8f4, reset
  0xffffbbee/0xffffbbf0; on failure count bbee (every 4th increments bbf0), bbc7.
- 0x2b7e2 `can212_rx_unpack`: bbf2=bbc0, bbf3=bbc1, bbf4=bbc2, bbf5=bbc3,
  bbde = bbc4*0x100+bbc5, bbf6 = bbc6.
- 0x2b1d6: bbac = bba4*0x100+bba5, bbae = bba6*0x100+bba7 (wheelspeeds).

## 3. Derived signals

- 0x2b314: validity timers — bbf2/bbf3/bbf4 != -1 reload bbe8/bbea/bbec = 0x1f,
  else count down.
- 0x2b3b8: bbd8 = clamp((bb20 * decode_u8_affine(0x3ec99326, 0, bbc8)/100 − bcb8) −
  bcbc, 0, 512); 512.0 when engine running + validity/fault flags. Consumers of
  0xffffbbd8: 0x1815c `dsc_timing_derate_select` (pool 0x1827c at 0x18188),
  0x17f20 (pool 0x18024 at 0x17f2c).
- 0x2b496: desired torque: bbe0 = bca0 − ((bb20*decode(bbc9))/100 − bcb8 − bcbc);
  bbf8 = filter(decode(bbc9), bbf8, 0.25, 0.19685039); bbf7 = encode_u8(bbf8);
  bbc9 = −2 engine stopped / 0xfe on invalid.
- Mode bits: 0x2b6a4 bbcf = (bbde & 8) == 8; 0x2b6c2 bbcb = (bbf6 & 0x80) &&
  engine running; 0x2b754 bbcc = (bbf6 & 0x40) && running; 0x2b788 bbcd =
  (bbf6 & 0x20); 0x2b7a6 bbce = (bbf6 & 0x10).
- 0x2b7c4: bbd0 = 0x1e < bbf0 (0x212 timeout).
- 0x2b046: rear wheelspeed average = encode((decode(bbac)+decode(bbae))/2) with
  decode_u16_affine(0x3c23d70a, 0xc2c80000); invalid handling for -1/0xffff.
- 0x2b156: bbb8 = vspeed <= 4.0 (clear at >= 5.0); read by 0x165d6 (pool 0x166ee).
- 0x2b17e/0x2b1aa: bbb9/bbba = (bbac/bbae == -1) || (bbbe > 0x1e).

## 4. Validation

A follow-up claims-verification pass re-ran the machine validators and re-read
every binary-level claim from the raw ROM/disassembly (see `validation.json`
`claim_verification`); it corrected the 0x212 descriptor DLC (7, not 8 — ctrl
byte 0x07 at ROM 0x4e222) and the 0x2a2ae callee count (13, not 12).

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256, 168,592
instruction bytes, 1,833 exact reference matches), `verify_claims.py`,
`verify_readability.py`, `verify_math_units.py`, `validate_reports.py` — all PASS;
`python -m pytest tests/` 134 passed. Labels applied by
`review_dsc_can_labels.py` + `annotate_source_review.py` +
`integrate_reviewed_names.py` (18 function rows, 10 RAM rows; 29 export files
renamed; 3,355 function bodies verified intact).

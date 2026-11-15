/* [ADDITIONAL SOURCE REVIEW]
 * diag_status_bit_pack [high]: 0x40 if DAT_ffffc1d0==1, |4 if DAT_ffffc274==1 (PID 0xc124) | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffc1d0 inferred_ram_c1d0_ffffc1d0 (uint8): PID 0xc124 -> 0x40
 * RAM 0xffffc274 inferred_ram_c274_ffffc274 (uint8): PID 0xc124 -> 4
 */
/* ROM address: 0x00037546; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037c66 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint diag_status_bit_pack(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (inferred_ram_c1d0_ffffc1d0_ffffc1d0 == '\x01') {
    uVar1 = 0x40;
  }
  if (inferred_ram_c274_ffffc274_ffffc274 == '\x01') {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}



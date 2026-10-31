/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a100: Table 2D - 114 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a114: Table 2D - 115 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a128: Table 2D - 116 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000148c4; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00014824 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000148c4(void)

{
  undefined **ppuVar1;
  float fVar2;
  
  if (DAT_ffffb534 == '\x01') {
    fVar2 = (float)lookup_2d_descriptor_scaled(&tbl_table_2d_114_0006a100);
  }
  else {
    if (DAT_ffffb53c == '\x01') {
      ppuVar1 = &tbl_table_2d_116_0006a128;
    }
    else {
      ppuVar1 = &tbl_table_2d_115_0006a114;
    }
    fVar2 = (float)lookup_2d_descriptor_scaled(DAT_ffffb5a8,ppuVar1);
  }
  DAT_ffffa7a4 = rx8_divide_with_zero_fallback(fVar2 * 0.6345 * 60.0,DAT_ffffa7ac);
  return;
}



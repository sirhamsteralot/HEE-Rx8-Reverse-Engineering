/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069370: Idle Target - Base (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693e8: Idle Target G (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0005fc40; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e54c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005fc40(void)

{
  undefined **ppuVar1;
  float fVar2;
  
  if (DAT_ffffb534 == '\0') {
    ppuVar1 = &tbl_idle_target_g_000693e8;
  }
  else {
    ppuVar1 = &tbl_idle_target_base_00069370;
  }
  fVar2 = (float)lookup_2d_descriptor_scaled(0x42a00000,ppuVar1);
  DAT_ffffd3b8 = fVar2 + -150.0;
  return;
}



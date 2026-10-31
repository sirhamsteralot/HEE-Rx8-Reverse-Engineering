/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003840c; body bytes: 150; decompiled */

uint FUN_0003840c(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float snapshot_DAT_ffffc4f0;
  float arg1;
  
  snapshot_DAT_ffffc4f0 = DAT_ffffc4f0;
  if (DAT_ffffc503 == 1) {
    DAT_ffffc4f8 = rx8_add_u16_saturate((int)DAT_ffffc4f8,1);
  }
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffc4f4,0x41200000);
  arg1 = 0.0;
  DAT_ffffc4f0 = rx8_max_float(fVar2 + (DAT_ffffc4c8 - inferred_coolant_temperature_ffffa98c) * 87891.0,0.0);
  uVar1 = (uint)DAT_ffffc503;
  if (uVar1 == 1) {
    DAT_ffffc4ec = rx8_max_float((DAT_ffffc4ec + DAT_ffffc4f0) - snapshot_DAT_ffffc4f0,arg1);
    uVar1 = extraout_r0;
  }
  return uVar1;
}



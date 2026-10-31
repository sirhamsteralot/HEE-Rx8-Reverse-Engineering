/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000553dc; body bytes: 78; decompiled */

undefined4 FUN_000553dc(void)

{
  char cVar1;
  undefined4 uVar2;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_engine_load_max_ffffc0b8;
  
  uVar2 = 0;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_load_max_ffffc0b8 = engine_load_max_ffffc0b8;
  cVar1 = rx8_is_outside_tolerance_band(engine_load_max_ffffc0b8,0,0x3727c5ac);
  if (cVar1 == '\0') {
    uVar2 = 0xff;
  }
  else {
    uVar2 = rx8_encode_u8_affine_saturate((snapshot_engine_load_ffffc0b4 * 100.0) / snapshot_engine_load_max_ffffc0b8,0x3ec8c8c8,uVar2);
  }
  return uVar2;
}



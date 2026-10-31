/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001805c; body bytes: 108; decompiled */

undefined4 * FUN_0001805c(void)

{
  undefined4 *puVar1;
  float snapshot_DAT_ffffa934;
  
  snapshot_DAT_ffffa934 = DAT_ffffa934;
  if (((0.00390625 <= DAT_ffffa948) && (DAT_ffffa934 < 0.00390625)) ||
     ((puVar1 = &DAT_0001812c, DAT_ffffa938 == 0 &&
      ((puVar1 = (undefined4 *)0x0, DAT_ffffa94c != 0 &&
       (puVar1 = (undefined4 *)(int)DAT_ffffa93a, puVar1 == (undefined4 *)0x0)))))) {
    puVar1 = (undefined4 *)rx8_lookup_3d_raw_u16(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&DAT_0006961c);
    DAT_ffffa93a = (short)puVar1;
  }
  else if (DAT_ffffa93a != 0) {
    DAT_ffffa93a = DAT_ffffa93a + -1;
  }
  DAT_ffffa948 = snapshot_DAT_ffffa934;
  return puVar1;
}



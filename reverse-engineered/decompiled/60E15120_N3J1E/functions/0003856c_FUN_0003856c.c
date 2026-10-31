/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003856c; body bytes: 90; decompiled */

uint FUN_0003856c(void)

{
  byte snapshot_engine_injectors_off_ffffa42c;
  uint uVar2;
  
  snapshot_engine_injectors_off_ffffa42c = engine_injectors_off_ffffa42c;
  uVar2 = (uint)DAT_ffffc4ff;
  if ((uVar2 == 1) && (40.0 <= DAT_ffffc4c8)) {
    uVar2 = rx8_add_u16_saturate((int)DAT_ffffc4fa,1);
    DAT_ffffc4fa = (short)uVar2;
  }
  if ((engine_running_ffffa428 == '\0') ||
     ((uVar2 = (uint)(char)DAT_ffffc524, uVar2 == 0 && (uVar2 = (uint)snapshot_engine_injectors_off_ffffa42c, uVar2 == 1)))) {
    DAT_ffffc4fc = 0;
  }
  DAT_ffffc524 = snapshot_engine_injectors_off_ffffa42c;
  return uVar2;
}



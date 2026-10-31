/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004f79e; body bytes: 124; decompiled */

undefined4 * FUN_0004f79e(void)

{
  ushort snapshot_DAT_ffffcfaa;
  undefined4 *puVar2;
  undefined4 *extraout_r0;
  undefined4 *extraout_r0_00;
  float arg1;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  puVar2 = (undefined4 *)(uint)DAT_ffffcfbf;
  if (puVar2 == (undefined4 *)0x1) {
    if (DAT_ffffcff8 == '\0') {
      puVar2 = (undefined4 *)&DAT_ffffcfa6;
      if (DAT_ffffcfa6 < DAT_ffffcfaa) {
        arg1 = DAT_ffffcfe0;
        DAT_ffffcfec = rx8_max_float(DAT_ffffcfec,DAT_ffffcfe0);
        puVar2 = extraout_r0;
        if (snapshot_DAT_ffffcfaa <= DAT_ffffcfa8) {
          DAT_ffffcff0 = rx8_min_float(DAT_ffffcff0,arg1);
          puVar2 = extraout_r0_00;
        }
      }
    }
    else {
      puVar2 = (undefined4 *)&DAT_ffffcfa8;
      DAT_ffffcfec = 0.0;
      if (DAT_ffffcfa8 < DAT_ffffcfaa) {
        puVar2 = &DAT_0004f830;
        DAT_ffffcff0 = 0.038;
      }
    }
  }
  return puVar2;
}



/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000516ba; body bytes: 138; decompiled */

uint FUN_000516ba(void)

{
  ushort snapshot_DAT_ffffcfaa;
  uint uVar2;
  uint extraout_r0;
  float arg0;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  arg0 = (inferred_lambda_actual_ffffadec_ffffadec + -1.0) * 100.0;
  uVar2 = (uint)DAT_ffffd0f2;
  if (uVar2 == 1) {
    uVar2 = 0x1f;
    if ((0x1e < DAT_ffffcfaa) && (uVar2 = 0x88, DAT_ffffcfaa < 0x89)) {
      arg0 = rx8_first_order_filter(arg0,DAT_ffffd0e4,0.25,1e-05);
      uVar2 = extraout_r0;
    }
    DAT_ffffd0e4 = arg0;
    if (snapshot_DAT_ffffcfaa == 0x3e) {
      DAT_ffffd0e8 = DAT_ffffd0e4;
    }
    arg0 = DAT_ffffd0e4;
    if (snapshot_DAT_ffffcfaa == 0x88) {
      DAT_ffffd0ec = DAT_ffffd0e4;
    }
  }
  DAT_ffffd0e4 = arg0;
  return uVar2;
}



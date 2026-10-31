/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003b906; body bytes: 176; decompiled */

uint FUN_0003b906(void)

{
  uint uVar1;
  uint extraout_r0;
  uint extraout_r0_00;
  float snapshot_DAT_ffffcf8c;
  
  uVar1 = 1;
  if ((DAT_ffffd1c5 == '\x01') || (uVar1 = (uint)DAT_ffffd1ad, uVar1 == 1)) {
    DAT_ffffc59c = DAT_ffffcf8c;
    DAT_ffffc5a0 = DAT_ffffcf8c;
    DAT_ffffc5a6 = '\x02';
    DAT_ffffc5a7 = '\x02';
  }
  else {
    snapshot_DAT_ffffcf8c = DAT_ffffcf8c;
    if (DAT_ffffc59c <= DAT_ffffcf8c) {
      if (DAT_ffffc5a6 == '\0') {
        DAT_ffffc5a6 = '\x02';
        DAT_ffffc59c = rx8_min_float(DAT_ffffc59c + 0.0625,DAT_ffffcf8c);
        uVar1 = extraout_r0;
      }
      else {
        DAT_ffffc5a6 = DAT_ffffc5a6 + -1;
      }
    }
    else {
      DAT_ffffc5a6 = '\x02';
      DAT_ffffc59c = DAT_ffffcf8c;
    }
    if (snapshot_DAT_ffffcf8c <= DAT_ffffc5a0) {
      if (DAT_ffffc5a7 == '\0') {
        DAT_ffffc5a7 = '\x02';
        DAT_ffffc5a0 = rx8_max_float(DAT_ffffc5a0 - 0.0625,snapshot_DAT_ffffcf8c);
        uVar1 = extraout_r0_00;
      }
      else {
        DAT_ffffc5a7 = DAT_ffffc5a7 + -1;
      }
    }
    else {
      DAT_ffffc5a7 = '\x02';
      DAT_ffffc5a0 = snapshot_DAT_ffffcf8c;
    }
  }
  return uVar1;
}



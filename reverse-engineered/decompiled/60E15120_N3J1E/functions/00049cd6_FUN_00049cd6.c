/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00049cd6; body bytes: 266; decompiled */

uint FUN_00049cd6(void)

{
  uint uVar1;
  float snapshot_DAT_ffffad20;
  
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  if (DAT_ffffd1c5 == 1) {
    DAT_ffffcd42 = 0;
    DAT_ffffcd50 = 0;
    DAT_ffffcd40 = 0xc35;
    uVar1 = 0xc35;
  }
  else {
    if (DAT_ffffcd42 == 0) {
      DAT_ffffcd40 = 0xc35;
    }
    uVar1 = (uint)DAT_ffffcd52;
    if ((((uVar1 == 0) || (4 < DAT_ffffcd42)) ||
        ((DAT_ffffad20 < 0.4 && ((0.3 <= DAT_ffffad20 && (0.05 <= DAT_ffffad20 - DAT_ffffcd54))))))
       || ((DAT_ffffcd58 == '\0' && (DAT_ffffad20 < 0.4)))) {
      DAT_ffffcd52 = 0;
      DAT_ffffcd50 = 0;
      uVar1 = (uint)DAT_ffffd1c5;
    }
    else if (uVar1 == 1) {
      if (DAT_ffffad20 < 0.3) {
        if (DAT_ffffcd42 < 5) {
          DAT_ffffcd52 = 0;
          DAT_ffffcd50 = rx8_add_u16_saturate((int)(short)DAT_ffffcd50,1);
          uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffcd42,1);
          DAT_ffffcd42 = (ushort)uVar1;
          if (DAT_ffffcd50 < DAT_ffffcd40) {
            DAT_ffffcd40 = DAT_ffffcd50;
          }
          DAT_ffffcd50 = 0;
        }
      }
      else if (DAT_ffffad20 < 0.4) {
        uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffcd50,1);
        DAT_ffffcd50 = (ushort)uVar1;
      }
    }
  }
  DAT_ffffcd54 = snapshot_DAT_ffffad20;
  DAT_ffffcd58 = DAT_ffffcd52;
  return uVar1;
}



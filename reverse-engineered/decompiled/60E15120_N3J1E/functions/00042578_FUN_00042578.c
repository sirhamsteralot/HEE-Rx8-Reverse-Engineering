/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042578; body bytes: 206; decompiled */

uint FUN_00042578(void)

{
  byte snapshot_DAT_ffffb358;
  uint uVar2;
  
  snapshot_DAT_ffffb358 = DAT_ffffb358;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc97f = 0;
    DAT_ffffc980 = 0;
    DAT_ffffc98e = 0;
    DAT_ffffc990 = 0;
    DAT_ffffc992 = 0;
    return 1;
  }
  if ((((DAT_ffffc978 != '\x01') || (DAT_ffffb358 != 1)) || (DAT_ffffc98e < 0x9d)) ||
     (DAT_ffffc974 < 17000.0)) {
    DAT_ffffc990 = 0;
  }
  else {
    if (DAT_ffffaa78 < 500.0) {
      if (3 < DAT_ffffc992) {
        DAT_ffffc980 = 1;
      }
      DAT_ffffc992 = rx8_add_u16_saturate((int)(short)DAT_ffffc992,1);
      DAT_ffffc990 = 0;
      goto LAB_0004266e;
    }
    if (0xf < DAT_ffffc990) {
      DAT_ffffc97f = 1;
    }
    DAT_ffffc990 = rx8_add_u16_saturate((int)(short)DAT_ffffc990,1);
  }
  DAT_ffffc992 = 0;
LAB_0004266e:
  uVar2 = (uint)snapshot_DAT_ffffb358;
  if (uVar2 == 1) {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffc98e,1);
    DAT_ffffc98e = (ushort)uVar2;
  }
  else {
    DAT_ffffc98e = 0;
  }
  return uVar2;
}



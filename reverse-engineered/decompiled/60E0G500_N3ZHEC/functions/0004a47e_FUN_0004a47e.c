/* ROM address: 0x0004a47e; body bytes: 266; decompiled */

uint FUN_0004a47e(void)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = DAT_ffffad98;
  if (DAT_ffffd201 == 1) {
    DAT_ffffcd82 = 0;
    DAT_ffffcd90 = 0;
    DAT_ffffcd80 = 0xc35;
    uVar1 = 0xc35;
  }
  else {
    if (DAT_ffffcd82 == 0) {
      DAT_ffffcd80 = 0xc35;
    }
    uVar1 = (uint)DAT_ffffcd92;
    if ((((uVar1 == 0) || (4 < DAT_ffffcd82)) ||
        ((DAT_ffffad98 < 0.4 && ((0.3 <= DAT_ffffad98 && (0.05 <= DAT_ffffad98 - DAT_ffffcd94))))))
       || ((DAT_ffffcd98 == '\0' && (DAT_ffffad98 < 0.4)))) {
      DAT_ffffcd92 = 0;
      DAT_ffffcd90 = 0;
      uVar1 = (uint)DAT_ffffd201;
    }
    else if (uVar1 == 1) {
      if (DAT_ffffad98 < 0.3) {
        if (DAT_ffffcd82 < 5) {
          DAT_ffffcd92 = 0;
          DAT_ffffcd90 = FUN_00002460((int)(short)DAT_ffffcd90,1);
          uVar1 = FUN_00002460((int)(short)DAT_ffffcd82,1);
          DAT_ffffcd82 = (ushort)uVar1;
          if (DAT_ffffcd90 < DAT_ffffcd80) {
            DAT_ffffcd80 = DAT_ffffcd90;
          }
          DAT_ffffcd90 = 0;
        }
      }
      else if (DAT_ffffad98 < 0.4) {
        uVar1 = FUN_00002460((int)(short)DAT_ffffcd90,1);
        DAT_ffffcd90 = (ushort)uVar1;
      }
    }
  }
  DAT_ffffcd94 = fVar2;
  DAT_ffffcd98 = DAT_ffffcd92;
  return uVar1;
}



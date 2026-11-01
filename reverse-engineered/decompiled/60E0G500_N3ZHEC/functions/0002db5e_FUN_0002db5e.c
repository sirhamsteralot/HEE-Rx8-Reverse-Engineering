/* ROM address: 0x0002db5e; body bytes: 230; decompiled */

uint FUN_0002db5e(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar2 = DAT_ffffbc37;
  bVar1 = DAT_ffffad90;
  uVar3 = FUN_0003eaa4(&DAT_ffff8690,0);
  uVar3 = uVar3 & 0xff;
  if (uVar3 == 1) {
    uVar4 = (uint)bVar1;
    uVar3 = uVar4;
    if ((uVar4 != 1) || (uVar3 = (uint)bVar2, uVar3 != 1)) {
      if ((uVar4 == 0) && (bVar2 == 0)) {
        DAT_ffffbd45 = 0;
        DAT_ffffbd48 = 0;
        DAT_ffffbd4a = 0;
        DAT_ffffbd50 = 0;
        return uVar3;
      }
      if (DAT_ffffbd50 != 1) {
        return (uint)DAT_ffffbd50;
      }
      if ((DAT_ffffbd48 != 0x177) && (DAT_ffffbd4a != 0x177)) {
        if ((uVar4 == 1) && (bVar2 == 0)) {
          uVar3 = FUN_00002460((int)DAT_ffffbd48,1);
          DAT_ffffbd48 = (short)uVar3;
          DAT_ffffbd4a = 0;
          return uVar3;
        }
        if (uVar4 != 0) {
          return uVar4;
        }
        if (bVar2 == 1) {
          DAT_ffffbd48 = 0;
          uVar3 = FUN_00002460((int)DAT_ffffbd4a,1);
          DAT_ffffbd4a = (short)uVar3;
          return uVar3;
        }
        return (uint)bVar2;
      }
      uVar3 = FUN_00002478((int)DAT_ffffbd45,1);
      DAT_ffffbd45 = (char)uVar3;
      DAT_ffffbd50 = 0;
      return uVar3;
    }
    DAT_ffffbd50 = 1;
    uVar3 = 1;
  }
  else {
    DAT_ffffbd45 = '\0';
    DAT_ffffbd50 = 0;
  }
  DAT_ffffbd4a = 0;
  DAT_ffffbd48 = 0;
  return uVar3;
}



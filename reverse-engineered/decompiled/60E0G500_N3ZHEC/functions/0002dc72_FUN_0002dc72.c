/* ROM address: 0x0002dc72; body bytes: 230; decompiled */

uint FUN_0002dc72(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar2 = DAT_ffffbc37;
  bVar1 = DAT_ffffad90;
  uVar3 = FUN_0003eaa4(&DAT_ffff8690,0);
  if ((uVar3 & 0xff) == 1) {
    uVar4 = (uint)bVar1;
    if ((uVar4 != 0) || (bVar2 != 0)) {
      if ((uVar4 == 1) && (bVar2 == 1)) {
        DAT_ffffbd46 = 0;
        DAT_ffffbd4c = 0;
        DAT_ffffbd4e = 0;
        DAT_ffffbd51 = 0;
        return 1;
      }
      if (DAT_ffffbd51 != 1) {
        return (uint)DAT_ffffbd51;
      }
      if ((DAT_ffffbd4c != 0x177) && (DAT_ffffbd4e != 0x177)) {
        if ((uVar4 == 1) && (bVar2 == 0)) {
          uVar3 = FUN_00002460((int)DAT_ffffbd4c,1);
          DAT_ffffbd4c = (short)uVar3;
          DAT_ffffbd4e = 0;
          return uVar3;
        }
        if (uVar4 != 0) {
          return uVar4;
        }
        if (bVar2 == 1) {
          DAT_ffffbd4c = 0;
          uVar3 = FUN_00002460((int)DAT_ffffbd4e,1);
          DAT_ffffbd4e = (short)uVar3;
          return uVar3;
        }
        return (uint)bVar2;
      }
      uVar3 = FUN_00002478((int)DAT_ffffbd46,1);
      DAT_ffffbd46 = (char)uVar3;
      DAT_ffffbd51 = 0;
      return uVar3;
    }
    DAT_ffffbd51 = 1;
  }
  else {
    DAT_ffffbd46 = '\0';
    DAT_ffffbd51 = 0;
  }
  DAT_ffffbd4e = 0;
  DAT_ffffbd4c = 0;
  return uVar3 & 0xff;
}



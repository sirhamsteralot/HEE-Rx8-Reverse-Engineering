/* ROM address: 0x0004257e; body bytes: 142; decompiled */

uint FUN_0004257e(void)

{
  uint uVar1;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffd201;
  if (uVar1 == 1) {
    DAT_ffffc986 = 0;
    DAT_ffffc988 = 0;
  }
  else {
    fVar2 = DAT_ffffb3c4;
    if (DAT_ffffb3c4 < 90.0) {
      uVar1 = (uint)DAT_ffffc980;
      if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd49, uVar1 == 0)) {
        uVar1 = FUN_00002460((int)DAT_ffffc986,1);
        DAT_ffffc986 = (short)uVar1;
      }
      else {
        DAT_ffffc986 = 0;
      }
    }
    if (10.0 <= fVar2) {
      uVar1 = (uint)DAT_ffffc980;
      if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd48, uVar1 == 1)) {
        uVar1 = FUN_00002460((int)DAT_ffffc988,1);
        DAT_ffffc988 = (short)uVar1;
      }
      else {
        DAT_ffffc988 = 0;
      }
    }
  }
  return uVar1;
}



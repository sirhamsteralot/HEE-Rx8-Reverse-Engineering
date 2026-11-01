/* ROM address: 0x0004cb4c; body bytes: 120; decompiled */

uint FUN_0004cb4c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffced4;
  if (uVar1 == 1) {
    if (DAT_ffffced3 == '\x01') {
      DAT_ffffcecf = FUN_00002478((int)DAT_ffffcecf,1);
    }
    if (DAT_ffffced0 == '\x01') {
      DAT_ffffcecc = FUN_00002478((int)DAT_ffffcecc,1);
    }
    if (DAT_ffffced1 == '\x01') {
      DAT_ffffcecd = FUN_00002478((int)DAT_ffffcecd,1);
    }
    uVar1 = (uint)DAT_ffffced2;
    if (uVar1 == 1) {
      uVar1 = FUN_00002478((int)DAT_ffffcece,1);
      DAT_ffffcece = (char)uVar1;
    }
  }
  return uVar1;
}



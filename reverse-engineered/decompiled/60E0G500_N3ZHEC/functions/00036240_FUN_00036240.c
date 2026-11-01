/* ROM address: 0x00036240; body bytes: 108; decompiled */

uint FUN_00036240(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_ffffc278;
  uVar2 = (uint)DAT_ffffc28e;
  if (uVar2 != 1) {
    DAT_ffffc28e = 5;
    if (DAT_ffffc282 != 0) {
      DAT_ffffc282 = DAT_ffffc282 + -1;
    }
    if (DAT_ffffc282 == 0) {
      FUN_00036320();
      DAT_ffffc28d = 5;
      uVar2 = FUN_00036720(200);
      DAT_ffffc282 = 500;
    }
    return uVar2;
  }
  while (DAT_ffffc278 == iVar1) {
    FUN_00036864();
  }
  DAT_ffffc27c = 500;
  uVar2 = FUN_00035e50();
  return uVar2;
}



/* ROM address: 0x0005942e; body bytes: 64; decompiled */

uint FUN_0005942e(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffd277;
  FUN_0005941c();
  uVar2 = (uint)DAT_ffffd201;
  if (uVar2 == 1) {
    uVar2 = FUN_00059474();
    return uVar2;
  }
  if ((bVar1 == 0) && (uVar2 = (uint)DAT_ffffd277, uVar2 == 1)) {
    uVar2 = FUN_000594b0();
    return uVar2;
  }
  return uVar2;
}



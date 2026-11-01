/* ROM address: 0x0005ae06; body bytes: 54; decompiled */

undefined4 FUN_0005ae06(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    FUN_0003ebe0(&DAT_ffff9138 + iVar2 * 8,0);
    uVar1 = FUN_0005b1dc(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return uVar1;
}



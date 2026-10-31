/* ROM address: 0x0000008a; body bytes: 54; decompiled */

uint FUN_0000008a(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_c [4];
  int iStack_8;
  
  uVar1 = *(byte *)(param_1 + 1) & 0xffffff07;
  if (uVar1 == 4) {
    iStack_8 = param_1;
    uVar2 = FUN_000000f4(param_1 + 2);
    local_c[0] = FUN_0000011a(DAT_ffffdfa0,uVar2);
    uVar1 = FUN_00000338(0xb0,1,local_c);
  }
  return uVar1;
}



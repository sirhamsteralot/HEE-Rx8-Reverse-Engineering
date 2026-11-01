/* ROM address: 0x0000fa0e; body bytes: 44; decompiled */

int FUN_0000fa0e(int param_1)

{
  int iVar1;
  
  param_1 = (uint)DAT_ffffa570 * 0x1e0000 - param_1;
  iVar1 = param_1 + -0x50000;
  if (iVar1 < 0x2d00000) {
    if (iVar1 < 0) {
      iVar1 = param_1 + 0x2cb0000;
    }
  }
  else {
    iVar1 = param_1 + -0x2d50000;
  }
  return iVar1;
}



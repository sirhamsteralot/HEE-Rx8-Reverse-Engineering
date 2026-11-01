/* ROM address: 0x0000ff32; body bytes: 102; decompiled */

int FUN_0000ff32(char *param_1)

{
  int iVar1;
  
  iVar1 = (int)*param_1;
  if (iVar1 == 0) {
    iVar1 = 0x40;
    *(int *)(param_1 + 0x20) = (int)((DAT_ffffa440 + -275.0) * 65536.0);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x20);
  }
  else if (iVar1 == 1) {
    *(int *)(param_1 + 0x20) = (int)(DAT_ffffa434 * 65536.0);
    *(int *)(param_1 + 0x38) = (int)(DAT_ffffa438 * 65536.0);
    iVar1 = 0x50;
    *(int *)(param_1 + 0x50) = (int)(DAT_ffffa43c * 65536.0);
  }
  return iVar1;
}



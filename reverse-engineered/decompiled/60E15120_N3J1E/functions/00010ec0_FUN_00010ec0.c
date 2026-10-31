/* ROM address: 0x00010ec0; body bytes: 108; decompiled */

uint FUN_00010ec0(char *param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_1;
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x28) = DAT_ffffbc24;
    *(undefined4 *)(param_1 + 0x18) = DAT_ffffbc24;
  }
  else if (uVar2 == 1) {
    uVar2 = (uint)(byte)param_1[8];
    if (uVar2 == 0) {
      sVar1 = -0x5874;
      *(int *)(param_1 + 0x28) = (int)((DAT_ffffa794 + -5.0) * 65536.0);
    }
    else {
      if (uVar2 != 1) {
        return uVar2;
      }
      sVar1 = -0x5870;
      *(int *)(param_1 + 0x28) = (int)((DAT_ffffa798 + -5.0) * 65536.0);
    }
    *(int *)(param_1 + 0x18) = (int)((*(float *)(int)sVar1 + -5.0) * 65536.0);
  }
  return uVar2;
}



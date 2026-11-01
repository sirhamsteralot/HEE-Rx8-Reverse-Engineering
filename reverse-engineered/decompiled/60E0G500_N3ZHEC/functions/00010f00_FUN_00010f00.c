/* ROM address: 0x00010f00; body bytes: 110; decompiled */

undefined4 * FUN_00010f00(char *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(int)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = &DAT_ffffbc90;
    *(undefined4 *)(param_1 + 0x28) = DAT_ffffbc8c;
    *(undefined4 *)(param_1 + 0x18) = DAT_ffffbc90;
  }
  else if (puVar2 == (undefined4 *)&UNK_00000001) {
    puVar2 = (undefined4 *)(uint)(byte)param_1[8];
    if (puVar2 == (undefined4 *)0x0) {
      sVar1 = -0x5864;
      *(int *)(param_1 + 0x28) = (int)((DAT_ffffa7a4 + -5.0) * 65536.0);
    }
    else {
      if (puVar2 != (undefined4 *)&UNK_00000001) {
        return puVar2;
      }
      sVar1 = -0x5860;
      *(int *)(param_1 + 0x28) = (int)((DAT_ffffa7a8 + -5.0) * 65536.0);
    }
    *(int *)(param_1 + 0x18) = (int)((*(float *)(int)sVar1 + -5.0) * 65536.0);
  }
  return puVar2;
}



/* ROM address: 0x0000047c; body bytes: 86; decompiled */

void FUN_0000047c(char param_1,byte param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  do {
  } while (DAT_ffffdff8 != -0x56);
  if ((param_1 == -0x20) || (param_1 == -0x28)) {
    DAT_ffffdff0 = 0;
  }
  else {
    DAT_ffffdff0 = 0x7a;
  }
  DAT_ffffdff1 = param_1 + param_2;
  puVar2 = &DAT_ffffdff2;
  bVar3 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      bVar3 = bVar3 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (bVar3 < param_2);
  }
  DAT_ffffdff8 = 0x55;
  return;
}



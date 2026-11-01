/* ROM address: 0x0000c338; body bytes: 150; decompiled */

void FUN_0000c338(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (DAT_ffffa38c == '\0') {
    if (0xb < param_1) {
      param_1 = param_1 - 0xc;
    }
    do {
      if (param_1 == (&DAT_0000d90e)[iVar1]) {
        DAT_ffffa383 = (undefined1)iVar1;
        iVar2 = 1;
        break;
      }
      if (param_1 == (&DAT_0000d910)[iVar1]) {
        iVar2 = 2;
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    if (iVar2 == 1) {
      FUN_0000c7ba();
      if (DAT_ffffa384 != -1) {
        FUN_0000c486();
        return;
      }
    }
    else if (iVar2 == 2) {
      FUN_0000c8dc();
      DAT_ffffa385 = 1;
    }
  }
  return;
}



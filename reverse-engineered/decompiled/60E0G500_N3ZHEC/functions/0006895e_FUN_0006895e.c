/* ROM address: 0x0006895e; body bytes: 56; decompiled */

void FUN_0006895e(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffde2f)[iVar1 * 2] == param_1) {
      FUN_00068504(iVar1);
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return;
}



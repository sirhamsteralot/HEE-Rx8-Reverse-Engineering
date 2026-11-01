/* ROM address: 0x0006928c; body bytes: 40; decompiled */

int FUN_0006928c(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffde2f)[iVar1 * 2] == param_1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return 0xff;
}



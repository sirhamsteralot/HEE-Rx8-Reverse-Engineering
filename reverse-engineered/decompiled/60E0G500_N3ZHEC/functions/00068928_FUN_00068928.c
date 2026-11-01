/* ROM address: 0x00068928; body bytes: 54; decompiled */

undefined1 * FUN_00068928(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_ffffde2f)[iVar2 * 2] == param_1) {
      puVar1 = (undefined1 *)FUN_0006861c(iVar2);
      return puVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return &DAT_ffffde2f;
}



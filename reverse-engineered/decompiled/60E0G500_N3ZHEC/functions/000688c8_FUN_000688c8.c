/* ROM address: 0x000688c8; body bytes: 54; decompiled */

undefined1 * FUN_000688c8(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_ffffde2f)[iVar2 * 2] == param_1) {
      puVar1 = (undefined1 *)FUN_000685c0(iVar2);
      return puVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return &DAT_ffffde2f;
}



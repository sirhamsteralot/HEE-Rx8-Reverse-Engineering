/* ROM address: 0x000009c0; body bytes: 30; decompiled */

uint FUN_000009c0(char *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)*param_1 | 1;
  *param_1 = (char)uVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}



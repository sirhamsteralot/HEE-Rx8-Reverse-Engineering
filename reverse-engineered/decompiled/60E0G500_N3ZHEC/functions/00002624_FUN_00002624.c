/* ROM address: 0x00002624; body bytes: 52; decompiled */

uint FUN_00002624(void)

{
  int in_r0;
  int iVar1;
  int iVar2;
  int in_r1;
  float in_fr0;
  
  iVar1 = (in_r0 - 1U) * 4;
  if (*(float *)(iVar1 + in_r1) <= in_fr0) {
    return in_r0 - 1U & 0x3fffffff;
  }
  do {
    iVar2 = iVar1;
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = iVar2 + -4;
  } while (in_fr0 < *(float *)(iVar2 + -4 + in_r1));
  return iVar2 - 4U >> 2;
}



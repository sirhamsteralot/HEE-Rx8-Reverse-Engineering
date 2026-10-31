/* ROM address: 0x00009ce0; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009ce0 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00009ce0(char *param_1,byte *param_2)

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



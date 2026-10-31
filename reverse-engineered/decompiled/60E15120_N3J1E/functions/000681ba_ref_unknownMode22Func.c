/* ROM address: 0x000681ba; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066aaa (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_unknownMode22Func(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar1 * 2] == param_1) {
      FUN_00067d60(iVar1);
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return;
}



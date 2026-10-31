/* ROM address: 0x00068ae8; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000673d8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00068ae8(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar1 * 2] == param_1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return 0xff;
}



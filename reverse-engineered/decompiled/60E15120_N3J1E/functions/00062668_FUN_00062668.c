/* ROM address: 0x00062668; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060f58 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062668(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 1;
  if (DAT_ffff87aa == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    _DAT_ffff87aa = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00067518(iVar3);
    if (cVar1 == '\0') {
      FUN_000675c2(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_0006791c(iVar3);
    }
  }
  else if (DAT_ffff87aa == '\x01') {
    uVar2 = 0;
  }
  else {
    _DAT_ffff87aa = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}



/* ROM address: 0x000543e4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000524c0 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_getTireSizeChecksumthing_(void)

{
  char cVar1;
  char local_8 [8];
  
  cVar1 = FUN_00037ef0(0x95,local_8,1);
  if (cVar1 == '\0') {
    if (local_8[0] == '*') {
      DAT_ffffd1b5 = 0;
      cVar1 = '*';
    }
    else {
      cVar1 = '\x01';
      DAT_ffffd1b5 = 1;
    }
  }
  return cVar1;
}



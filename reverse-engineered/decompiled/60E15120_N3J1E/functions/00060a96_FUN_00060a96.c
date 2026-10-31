/* ROM address: 0x00060a96; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f386 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060a96(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_0006328a(0);
  while (cVar1 == '\x01') {
    if (DAT_ffffd797 == -0x40) {
      if (iVar2 == 0) {
        iVar2 = 0xc0;
      }
    }
    else if (DAT_ffffd797 == -0x80) {
      iVar2 = 0x80;
    }
    cVar1 = FUN_0006328a(1);
  }
  DAT_ffff8780 = rx8_pack_u8_with_complement(iVar2);
  return;
}



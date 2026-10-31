/* ROM address: 0x000544c4; body bytes: 154; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000525a0 (154 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000544c4(void)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  byte local_24;
  byte local_23;
  
  bVar1 = false;
  uVar4 = 0x80;
  sVar3 = 0;
  do {
    cVar2 = FUN_00037ef0(uVar4,&local_24,2);
    if (cVar2 == '\x01') {
      bVar1 = true;
    }
    uVar4 = uVar4 + 2;
    sVar3 = sVar3 + (ushort)local_24 * 0x100 + (ushort)local_23;
  } while ((uVar4 & 0xffff) < 0x100);
  if (!bVar1) {
    if ((sVar3 == 0) || (cVar2 = DAT_ffffd1b5, DAT_ffffd1b5 == '\x01')) {
      DAT_ffffd1b8 = 0;
    }
    else {
      DAT_ffffd1b8 = 1;
    }
  }
  return cVar2;
}



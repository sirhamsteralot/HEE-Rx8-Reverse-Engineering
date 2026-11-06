/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffb478 e2ram_read_staging (uint16[28]): E2RAM read landing buffer (0xb958, 0x1c u16); magic checked byte-swapped as 0x5aa5 at +0, checksum at +0x36 (0xffffb4ae).
 */
/* ROM address: 0x000235f8; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023e6c (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000235f8(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  short sVar4;
  char cVar5;
  
  if (DAT_ffffa228 == '\0') {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffb438,1);
    DAT_ffffb438 = (short)uVar1;
  }
  else {
    DAT_ffffb438 = 0;
    cVar5 = DAT_ffffa228 == '\x02';
    FUN_0000b958(&e2ram_read_staging_ffffb478,0x1c);
    DAT_ffffb43d = e2ram_read_staging_ffffb478 != 0x5aa5;
    sVar4 = 0;
    if ((bool)DAT_ffffb43d) {
      cVar5 = cVar5 + '\x01';
    }
    bVar3 = 0;
    iVar2 = 0;
    do {
      bVar3 = bVar3 + 1;
      sVar4 = sVar4 + *(short *)((int)&e2ram_read_staging_ffffb478 + iVar2);
      iVar2 = iVar2 + 2;
    } while (bVar3 < 0x1b);
    DAT_ffffb43e = sVar4 != DAT_ffffb4ae;
    if ((bool)DAT_ffffb43e) {
      cVar5 = cVar5 + '\x01';
    }
    uVar1 = 0x36;
    if (cVar5 == '\0') {
      DAT_ffffb43a = 0;
      uVar1 = e2ram_load_decode_entry();
      return uVar1;
    }
    DAT_ffffb43a = 1;
  }
  return uVar1;
}



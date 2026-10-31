/* ROM address: 0x00063efc; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000627ec (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063efc(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = (int)DAT_ffff8e6c._0_1_;
  pcVar1 = &DAT_ffff8d54;
  do {
    iVar2 = iVar2 + *pcVar1;
    DAT_ffff8e6c = rx8_pack_u8_with_complement(iVar2);
    *pcVar1 = '\0';
    DAT_ffff8e6e = rx8_pack_u8_with_complement(iVar2);
    pcVar1 = pcVar1 + 2;
  } while (pcVar1 < &DAT_ffff8e6c);
  return;
}



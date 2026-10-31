/* ROM address: 0x000626d4; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060fc4 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000626d4(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87ac._0_1_ == '\x02') {
    DAT_ffff87a0 = rx8_pack_u16_with_complement(param_1);
    DAT_ffff87ac = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00067a88(param_1);
    if (cVar1 == '\0') {
      FUN_00067b28(param_1);
    }
    else if (cVar1 == '\x01') {
      FUN_00067cc2(param_1);
    }
  }
  else if (DAT_ffff87ac._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87ac = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}



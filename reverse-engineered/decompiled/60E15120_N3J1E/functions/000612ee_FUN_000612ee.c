/* ROM address: 0x000612ee; body bytes: 266; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0005fbde (266 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000612ee(void)

{
  char cVar1;
  
  FUN_00064530();
  if ((DAT_ffff8e7c == '\x01') && (DAT_ffff878c._0_1_ == '\0')) {
    DAT_ffff878c = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_0006328a(0);
    while (cVar1 == '\x01') {
      FUN_000623a0((int)(short)DAT_ffffd790);
      cVar1 = (&DAT_0007e32a)[DAT_ffffd790];
      if (cVar1 == '\0') {
        FUN_00060ca6(&DAT_ffffd790);
      }
      else if (cVar1 == '\x01') {
        FUN_00064918(&DAT_ffffd790);
      }
      else if (cVar1 == '\x02') {
        FUN_00064972(&DAT_ffffd790);
      }
      else if (cVar1 == '\x03') {
        FUN_0006400a(&DAT_ffffd790);
      }
      FUN_000606be();
      FUN_000627a0();
      cVar1 = FUN_0006328a(1);
    }
    FUN_00060a96();
  }
  FUN_0006455c();
  _DAT_ffff8e7c = rx8_pack_u8_with_complement(0);
  FUN_00063efc();
  cVar1 = DAT_ffff8e7e;
  _DAT_ffff8e7e = rx8_pack_u8_with_complement(0);
  FUN_00062040((int)cVar1);
  FUN_00060592();
  DAT_ffff878c = rx8_pack_u8_with_complement(0);
  return;
}



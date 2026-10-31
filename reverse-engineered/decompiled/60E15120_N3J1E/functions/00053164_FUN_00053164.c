/* ROM address: 0x00053164; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000510e8 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00053164(void)

{
  ushort uVar1;
  
  uVar1 = rx8_add_u16_saturate(0x4e,0x10);
  if (DAT_ffffd144 == '\x02') {
    if (uVar1 <= DAT_ffffcfaa) {
      DAT_ffffd148 = 0;
      DAT_ffffd149 = 1;
      return &DAT_0007dc27;
    }
    DAT_ffffd148 = 1;
  }
  else {
    DAT_ffffd148 = 0;
  }
  DAT_ffffd149 = 0;
  return &DAT_0007dc27;
}



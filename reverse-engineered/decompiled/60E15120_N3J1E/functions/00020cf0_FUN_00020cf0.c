/* ROM address: 0x00020cf0; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002165c (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00020cf0(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_ffffad50 < 0.0) || ((DAT_ffffb285 == 0 && (0xf9 < DAT_ffffb286)))) {
    DAT_ffffb270 = '\0';
  }
  uVar2 = (uint)DAT_ffffb285;
  uVar1 = uVar2;
  if (uVar2 == 1) {
    uVar1 = rx8_add_u8_saturate((int)DAT_ffffb270,1);
    DAT_ffffb270 = (char)uVar1;
  }
  if (uVar2 == 0) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffb286,1);
    DAT_ffffb286 = (ushort)uVar1;
  }
  else {
    DAT_ffffb286 = 0;
  }
  return uVar1;
}



/* ROM address: 0x00048c7a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00047d06 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00048c7a(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffccbd;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffccb8,1);
    DAT_ffffccb8 = (short)uVar1;
  }
  else {
    DAT_ffffccb8 = 0;
  }
  return uVar1;
}



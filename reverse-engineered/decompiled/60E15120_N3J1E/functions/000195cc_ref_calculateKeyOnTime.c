/* ROM address: 0x000195cc; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001a2e8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_calculateKeyOnTime(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffaa68;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffa9e0,1);
    DAT_ffffa9e0 = (short)uVar1;
  }
  else {
    DAT_ffffa9e0 = 0;
  }
  return uVar1;
}



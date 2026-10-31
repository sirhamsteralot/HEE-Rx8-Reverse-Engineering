/* ROM address: 0x00032378; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032820 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_debounceCruiseControlACCELRES(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbc36;
  if (DAT_ffffbfb5 == '\x01') {
    if (uVar1 == 0) {
      DAT_ffffbfcf = '\x01';
    }
  }
  else {
    DAT_ffffbfcf = '\0';
  }
  if (((DAT_ffffbced == '\x01') &&
      (((DAT_ffffbfb5 == '\0' || (DAT_ffffbfcf == '\x01')) && (DAT_ffffbfc2 == 0x3e)))) &&
     (uVar1 == 1)) {
    DAT_ffffbfb9 = 1;
  }
  else if (uVar1 == 0) {
    DAT_ffffbfb9 = 0;
  }
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffbfc2,1);
    DAT_ffffbfc2 = (short)uVar1;
  }
  else {
    DAT_ffffbfc2 = 0;
  }
  return uVar1;
}



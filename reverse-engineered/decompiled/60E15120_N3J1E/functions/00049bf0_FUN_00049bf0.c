/* ROM address: 0x00049bf0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00048af4 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00049bf0(void)

{
  char cVar1;
  
  if (DAT_ffffcd34 == '\0') {
    DAT_ffffcd2c = 0;
  }
  else {
    cVar1 = rx8_is_outside_tolerance_band(DAT_ffffcd2c,0,0x3727c5ac);
    if ((cVar1 != '\0') && (0.3 <= DAT_ffffad20)) {
      DAT_ffffcd2c = mass_air_flow_ffffa9ec;
    }
  }
  return;
}



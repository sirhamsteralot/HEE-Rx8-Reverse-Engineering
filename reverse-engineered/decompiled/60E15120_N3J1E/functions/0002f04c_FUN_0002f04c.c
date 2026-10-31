/* ROM address: 0x0002f04c; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f504 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002f04c(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffbd93;
  if (inferred_coolant_temperature_ffffa98c < 110.0) {
    if (inferred_coolant_temperature_ffffa98c < 107.5) {
      DAT_ffffbd93 = '\0';
    }
  }
  else {
    DAT_ffffbd93 = '\x01';
  }
  if (DAT_ffffbd8a == 0) {
    if ((DAT_ffffbd93 == '\x01') && (DAT_ffffbd8a = 0x138, cVar1 != '\0')) {
      if (DAT_ffffbd76 == '\x01') {
        DAT_ffffbd76 = '\0';
      }
      else {
        DAT_ffffbd76 = '\x01';
      }
    }
    else {
      DAT_ffffbd76 = '\x01';
    }
  }
  if (DAT_ffffbd8a != 0) {
    DAT_ffffbd8a = DAT_ffffbd8a + -1;
  }
  return;
}



/* ROM address: 0x0003e51e; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003eaba (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_coolantTempModelBooleans(void)

{
  if (400.0 <= DAT_ffffc640) {
    if (500.0 < DAT_ffffc640) {
      DAT_ffffc64c = 1;
    }
  }
  else {
    DAT_ffffc64c = 0;
  }
  if (850.0 <= DAT_ffffc640) {
    if (1000.0 < DAT_ffffc640) {
      DAT_ffffc64d = 1;
    }
  }
  else {
    DAT_ffffc64d = 0;
  }
  return;
}



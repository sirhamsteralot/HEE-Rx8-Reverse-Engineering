/* ROM address: 0x000474b2; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004653e (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setPerRotorLevel1FuelCut(byte param_1)

{
  if (param_1 < 4) {
    DAT_ffffcc72 = (param_1 & 1) == 1;
    if ((param_1 & 2) == 2) {
      DAT_ffffcc73 = 1;
    }
    else {
      DAT_ffffcc73 = 0;
    }
  }
  else {
    DAT_ffffcc72 = false;
    DAT_ffffcc73 = 0;
  }
  return;
}



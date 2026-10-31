/* ROM address: 0x0002a158; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a8ac (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_0002a158(void)

{
  byte bVar1;
  
  if ((((DAT_ffffbb17 & 0x80) == 0x80) || (bVar1 = DAT_ffffbb17 & 0x40, bVar1 == 0x40)) ||
     (inferred_coolant_temperature_ffffa98c <= 0.0)) {
    bVar1 = 0;
    DAT_ffffbb4a = 0;
  }
  else {
    DAT_ffffbb4a = 1;
  }
  return bVar1;
}



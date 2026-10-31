/* ROM address: 0x0002b754; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bea8 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte ref_DSC_checkIfMode_x40(void)

{
  byte bVar1;
  
  bVar1 = DAT_ffffbbf6 & 0x40;
  if ((bVar1 == 0x40) && (bVar1 = engine_running_ffffa428, engine_running_ffffa428 == 1)) {
    DAT_ffffbbcc = 1;
  }
  else {
    DAT_ffffbbcc = 0;
  }
  return bVar1;
}



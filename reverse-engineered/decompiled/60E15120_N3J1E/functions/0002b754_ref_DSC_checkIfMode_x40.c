/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_bit40_check [medium]: 0xffffbbcc = 1 when (0xffffbbf6 & 0x40) == 0x40 && engine running. Pool 0x2a47c.
 */
/* ROM address: 0x0002b754; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bea8 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte candidate_dsc_mode_bit40_check(void)

{
  byte bVar1;
  
  bVar1 = dsc_mode_byte_ffffbbf6 & 0x40;
  if ((bVar1 == 0x40) && (bVar1 = engine_running_ffffa428, engine_running_ffffa428 == 1)) {
    DAT_ffffbbcc = 1;
  }
  else {
    DAT_ffffbbcc = 0;
  }
  return bVar1;
}



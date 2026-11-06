/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_bit10_check [medium]: 0xffffbbce = ((0xffffbbf6 & 0x10) == 0x10). Pool 0x2a484.
 */
/* ROM address: 0x0002b7a6; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002befa (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 candidate_dsc_mode_bit10_check(void)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = (dsc_mode_byte_ffffbbf6 & 0x10) != 0x10;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  DAT_ffffbbce = !bVar1;
  return uVar2;
}



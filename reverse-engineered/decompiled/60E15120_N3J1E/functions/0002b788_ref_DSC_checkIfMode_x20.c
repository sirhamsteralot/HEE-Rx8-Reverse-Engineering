/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_bit20_check [medium]: 0xffffbbcd = ((0xffffbbf6 & 0x20) == 0x20). Pool 0x2a480.
 */
/* ROM address: 0x0002b788; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bedc (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 candidate_dsc_mode_bit20_check(void)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = (dsc_mode_byte_ffffbbf6 & 0x20) != 0x20;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20;
  }
  DAT_ffffbbcd = !bVar1;
  return uVar2;
}



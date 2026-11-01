/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffa3e4; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0001ae5c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b90c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001ae5c(void)

{
  inferred_o2s2_ffffad1c_ffffad1c = rx8_encode_u16_affine_saturate(DAT_ffffa3e4,0x38a00000,0);
  return;
}



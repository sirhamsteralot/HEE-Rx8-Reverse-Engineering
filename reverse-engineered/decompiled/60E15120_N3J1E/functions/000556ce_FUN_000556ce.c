/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_ad10 [medium]: PID 0x33: ffffad10*25.325+0.0182
 * RAM 0xffffad10 inferred_ram_ad10_ffffad10 (float): PID 0x33/0x16b3
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffad10 * 25.325 + 0.0182; decode = raw * 1 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000556ce; body bytes: 30; decompiled */

undefined4 candidate_diag_encode_ad10(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_ram_ad10_ffffad10_ffffad10 * 25.325 + 0.0182,0x3f800000,0);
  return uVar1;
}



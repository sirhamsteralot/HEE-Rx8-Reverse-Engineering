/* [ADDITIONAL SOURCE REVIEW]
 * diag_afr_word_a [medium]: Encodes DAT_ffffaa6c (step 0x38000000) as the high u16 word of PID 0x0034 'Air Fuel Ratio'.
 * RAM 0xffffaa6c diag_afr_word_a (float): Encoded (step 0x38000000) as high word of PID 0x0034 'Air Fuel Ratio'.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): diag_afr_word_a_ffffaa6c; decode = raw * 3.051757812e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000556ec; body bytes: 22; decompiled */

undefined4 diag_read_afr_word_a(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(diag_afr_word_a_ffffaa6c,0x38000000,0);
  return uVar1;
}



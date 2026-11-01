/* [ADDITIONAL SOURCE REVIEW]
 * diag_afr_word_b [medium]: Encodes DAT_ffffaa7c (mult 0x3b800000, offset 0xc3000000 = -96.0) as the low u16 word of PID 0x0034.
 * RAM 0xffffaa7c diag_afr_word_b (float): Encoded (mult 0.0625, offset -96.0) as low word of PID 0x0034.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): diag_afr_word_b_ffffaa7c; decode = raw * 0.00390625 + (-128) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055702; body bytes: 24; decompiled */

undefined4 diag_read_afr_word_b(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(diag_afr_word_b_ffffaa7c,0x3b800000,0xc3000000);
  return uVar1;
}



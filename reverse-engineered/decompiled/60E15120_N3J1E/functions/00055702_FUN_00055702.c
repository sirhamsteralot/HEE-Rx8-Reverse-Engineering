/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_afr_word_b [high]: PID 0x0034 handler second word; encodes diag_afr_word_b_ffffaa7c * 0.00390625 (0x3b800000) offset -128 (0xc3000000); logger 0x220034 AFR
 * RAM 0xffffaa7c diag_afr_word_b (float): Encoded (mult 0.0625, offset -96.0) as low word of PID 0x0034.
 */
/* ROM address: 0x00055702; body bytes: 24; decompiled */

undefined4 diag_read_afr_word_b(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(diag_afr_word_b_ffffaa7c,0x3b800000,0xc3000000);
  return uVar1;
}



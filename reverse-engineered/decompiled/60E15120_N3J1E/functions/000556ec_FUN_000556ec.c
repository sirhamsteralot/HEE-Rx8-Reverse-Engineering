/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_afr_word_a [high]: PID 0x0034 handler 0x56b22 (diag22_pid0034_afr_lambda_words) calls it; encodes diag_afr_word_a_ffffaa6c * 3.05176e-05 (0x38000000 in pool); logger 0x220034 AFR
 * RAM 0xffffaa6c diag_afr_word_a (float): Encoded (step 0x38000000) as high word of PID 0x0034 'Air Fuel Ratio'.
 */
/* ROM address: 0x000556ec; body bytes: 22; decompiled */

undefined4 diag_read_afr_word_a(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(diag_afr_word_a_ffffaa6c,0x38000000,0);
  return uVar1;
}



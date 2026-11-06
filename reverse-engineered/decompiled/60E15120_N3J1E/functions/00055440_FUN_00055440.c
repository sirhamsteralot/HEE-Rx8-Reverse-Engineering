/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_stft_lambda [high]: PID 0x06: (ffffadec-1)*100*0.78125-100
 * RAM 0xffffadec inferred_lambda_actual_ffffadec (float): PID 0x06: (x-1)*100 trim; fuel-chain cell listed in ROADMAP group C
 */
/* ROM address: 0x00055440; body bytes: 38; decompiled */

undefined4 diag_encode_stft_lambda(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate((inferred_lambda_actual_ffffadec_ffffadec + -1.0) * 100.0,0x3f480000,0xc2c80000);
  return uVar1;
}



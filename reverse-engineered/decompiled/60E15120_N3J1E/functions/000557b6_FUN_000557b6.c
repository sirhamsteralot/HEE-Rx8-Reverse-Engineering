/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_a9c4 [medium]: PID 0x49: ffffa9c4 decode*20*0.392157
 * RAM 0xffffa9c4 inferred_pedal_volts_ffffa9c4 (uint16): PID 0x49/0x0914
 */
/* ROM address: 0x000557b6; body bytes: 44; decompiled */

void candidate_diag_encode_a9c4(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u16_affine(0x38a00000,0,(int)inferred_pedal_volts_ffffa9c4_ffffa9c4);
  rx8_encode_u8_affine_saturate(fVar1 * 20.0,0x3ec8c8c8,uVar2);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_a9c6 [medium]: PID 0x4a: ffffa9c6 decode*20*0.392157
 * RAM 0xffffa9c6 inferred_pedal_volts_ffffa9c6 (uint16): PID 0x4a/0x0915
 */
/* ROM address: 0x00055838; body bytes: 44; decompiled */

void diag_encode_a9c6(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u16_affine(0x38a00000,0,(int)inferred_pedal_volts_ffffa9c6_ffffa9c6);
  rx8_encode_u8_affine_saturate(fVar1 * 20.0,0x3ec8c8c8,uVar2);
  return;
}



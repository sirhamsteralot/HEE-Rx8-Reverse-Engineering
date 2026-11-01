/* ROM address: 0x0005553e; body bytes: 44; decompiled */

void diag_encode_throttle_pct(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u16_affine(0x38a00000,0,(int)inferred_throttle_sensor_volts_ffffad5c_ffffad5c);
  rx8_encode_u8_affine_saturate(fVar1 * 20.0,0x3ec8c8c8,uVar2);
  return;
}



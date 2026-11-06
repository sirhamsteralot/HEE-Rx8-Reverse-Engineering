/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_throttle_pct [high]: PID 0x11: ffffad5c*20*0.392157
 * RAM 0xffffad5c inferred_throttle_sensor_volts_ffffad5c (uint16): Read by diag_encode_throttle_pct 0x5553e (PID 0x11) and handlers 0x56d58 (PID 0x0917) / 0x56eb8 (PID 0x1154); also written in the APP/throttle chain (literal 0xad5c at 0x1b0e6/0x4561c/0x47186); decode 7.62939e-05 V/count *20 -> %
 */
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



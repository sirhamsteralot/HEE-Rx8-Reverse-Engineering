/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_ad5e [high]: PID 0x47: ffffad5e decode*20*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffad5e inferred_pedal_volts_ffffad5e (uint16): PID 0x47/0x0918
 */
/* ROM address: 0x0005578a; body bytes: 44; decompiled */

void diag_encode_ad5e(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u16_affine(0x38a00000,0,(int)inferred_pedal_volts_ffffad5e_ffffad5e);
  rx8_encode_u8_affine_saturate(fVar1 * 20.0,0x3ec8c8c8,uVar2);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_o2s2 [medium]: PID 0x15: ffffad1c decode*0.005
 * RAM 0xffffad1c inferred_o2s2_ffffad1c (uint16): PID 0x15: decode(7.63e-05)*0.005
 */
/* ROM address: 0x00055586; body bytes: 38; decompiled */

void diag_encode_o2s2(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)inferred_o2s2_ffffad1c_ffffad1c);
  rx8_encode_u8_affine_saturate(uVar1,0x3ba3d70a,uVar2);
  return;
}



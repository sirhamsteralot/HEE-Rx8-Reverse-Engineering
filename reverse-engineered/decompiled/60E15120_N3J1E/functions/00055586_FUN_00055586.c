/* ROM address: 0x00055586; body bytes: 38; decompiled */

void candidate_diag_encode_o2s2(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)inferred_o2s2_ffffad1c_ffffad1c);
  rx8_encode_u8_affine_saturate(uVar1,0x3ba3d70a,uVar2);
  return;
}



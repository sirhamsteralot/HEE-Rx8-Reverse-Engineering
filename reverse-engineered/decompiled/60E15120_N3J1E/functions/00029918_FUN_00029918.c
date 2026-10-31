/* ROM address: 0x00029918; body bytes: 42; decompiled */

void FUN_00029918(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = rx8_clamp_float(DAT_ffffbb20,0.0,508.0);
  DAT_ffffbb1c = rx8_encode_u8_affine_saturate(fVar1,0x40000000,uVar2);
  return;
}



/* ROM address: 0x0000d13c; body bytes: 8; decompiled */

undefined4 FUN_0000d13c(void)

{
  undefined4 uVar1;
  float fVar2;
  
  DAT_ffffa3e2 = DAT_ffff9f18;
  DAT_ffffa3e2 = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f18,DAT_ffff9f18,0x100);
  fVar2 = (float)rx8_decode_u16_affine(0x38a00000,0,(int)(short)DAT_ffffa3e2);
  DAT_ffffa3dc = fVar2 * 25.325 + 0.0182;
  if (DAT_ffffa3e2 < 0xf5c3) {
    if (0xa3c < DAT_ffffa3e2) {
      DAT_ffffa3e0 = 0;
      return 0xa3d;
    }
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  DAT_ffffa3e0 = (char)uVar1;
  return uVar1;
}



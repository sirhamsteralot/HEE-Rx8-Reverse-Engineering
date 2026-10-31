/* ROM address: 0x00007330; body bytes: 8; decompiled */

undefined4 * FUN_00007330(void)

{
  DAT_ffff9f6c = DAT_ffff9f00;
  DAT_ffff9f6c = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f00,DAT_ffff9f00,0x100);
  DAT_ffff9f68 = ((float)DAT_ffff9f6c / 65536.0) * 20.0;
  return &DAT_0000738c;
}



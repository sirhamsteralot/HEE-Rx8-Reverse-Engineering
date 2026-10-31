/* ROM address: 0x00029fdc; body bytes: 80; decompiled */

undefined4 FUN_00029fdc(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb40 = 0xffff;
    uVar2 = 1;
  }
  else if (engine_running_ffffa428 == '\0') {
    DAT_ffffbb40 = 0x200;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc4000000;
    fVar1 = rx8_clamp_float(DAT_ffffbcb4,-512.0,65022.0);
    uVar2 = rx8_encode_u16_affine_saturate(fVar1,0x3f800000,uVar2);
    DAT_ffffbb40 = (undefined2)uVar2;
  }
  return uVar2;
}



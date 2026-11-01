/* ROM address: 0x00023ac0; body bytes: 42; decompiled */

uint FUN_00023ac0(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffccfb;
  if (uVar1 == 1) {
    DAT_ffffb474 = rx8_max_float(1.0,1.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffb474 = 0.0;
  }
  return uVar1;
}



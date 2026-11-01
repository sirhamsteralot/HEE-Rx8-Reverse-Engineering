/* ROM address: 0x000444b0; body bytes: 58; decompiled */

uint FUN_000444b0(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffcab4;
  if (uVar1 == 1) {
    DAT_ffffca24 = rx8_clamp_float(DAT_ffffbcfc,0.0009999999,0.099999994);
    DAT_ffffca20 = (DAT_ffffca28 * DAT_ffffbd04) / DAT_ffffca24;
    uVar1 = extraout_r0;
  }
  return uVar1;
}



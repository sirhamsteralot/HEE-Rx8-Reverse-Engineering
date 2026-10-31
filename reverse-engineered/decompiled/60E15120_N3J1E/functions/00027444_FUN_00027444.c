/* ROM address: 0x00027444; body bytes: 120; decompiled */

uint FUN_00027444(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = rx8_is_outside_tolerance_band(DAT_ffffb2f0,0,0x3727c5ac);
  if ((uint)DAT_ffffba1c == (uVar1 & 0xff)) {
    uVar2 = rx8_add_u8_saturate((int)DAT_ffffba1b,1);
    DAT_ffffba1b = (char)uVar2;
  }
  else {
    DAT_ffffba1b = 0;
    uVar2 = uVar1;
  }
  if (engine_injectors_off_ffffa42c == '\0') {
    uVar2 = rx8_add_u8_saturate((int)DAT_ffffba19,1);
    DAT_ffffba19 = (char)uVar2;
  }
  else {
    DAT_ffffba19 = 0;
  }
  if (DAT_ffffb0ca == '\0') {
    uVar2 = rx8_add_u8_saturate((int)DAT_ffffba1a,1);
    DAT_ffffba1a = (char)uVar2;
  }
  else {
    DAT_ffffba1a = 0;
  }
  DAT_ffffba1c = (char)uVar1;
  return uVar2;
}



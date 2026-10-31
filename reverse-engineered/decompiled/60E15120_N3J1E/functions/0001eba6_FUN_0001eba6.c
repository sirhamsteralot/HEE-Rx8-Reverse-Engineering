/* ROM address: 0x0001eba6; body bytes: 246; decompiled */

uint FUN_0001eba6(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffb07d;
  if (((((uVar1 != 1) || (DAT_ffffb116 = '\x01', DAT_ffffb112 < 0xea6)) || (DAT_ffffb114 < 10)) ||
      (((inferred_coolant_temperature_ffffa98c < 40.0 || (mass_air_flow_ffffa9ec < 8.0)) ||
       ((100.0 <= mass_air_flow_ffffa9ec || ((0.0001 <= DAT_ffffae04 || (DAT_ffffaa62 != '\0')))))))) ||
     ((DAT_ffffae20 != '\0' ||
      ((((DAT_ffffcac8 != '\0' || (DAT_ffffc704 != '\0')) || (DAT_ffffae0c < -0.05)) ||
       (0.05 < DAT_ffffae0c)))))) {
    DAT_ffffb108 = 0;
  }
  else {
    DAT_ffffb108 = 1;
  }
  if (DAT_ffffb116 == '\x01') {
    DAT_ffffb112 = rx8_add_u16_saturate((int)(short)DAT_ffffb112,1);
  }
  else {
    DAT_ffffb112 = 0;
  }
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffb114,1);
    DAT_ffffb114 = (ushort)uVar1;
  }
  else {
    DAT_ffffb114 = 0;
  }
  return uVar1;
}



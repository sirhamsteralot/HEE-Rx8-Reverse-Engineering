/* ROM address: 0x0002bc5a; body bytes: 102; decompiled */

uint FUN_0002bc5a(void)

{
  uint uVar1;
  
  if (-5.0 <= inferred_coolant_temperature_ffffa98c) {
    DAT_ffffbc2b = 1;
  }
  if (-5.0 <= intake_air_temperature_ffffaddc) {
    DAT_ffffbc2c = 1;
  }
  uVar1 = (uint)DAT_ffffbc2b;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffbc2c, uVar1 == 1)) {
    uVar1 = rx8_add_u8_saturate(10,1);
    DAT_ffffbc2a = (char)uVar1;
  }
  if (DAT_ffffbc2a == '\0') {
    uVar1 = 0;
    DAT_ffffbc24 = 0;
  }
  else {
    DAT_ffffbc24 = 0xffe20000;
  }
  return uVar1;
}



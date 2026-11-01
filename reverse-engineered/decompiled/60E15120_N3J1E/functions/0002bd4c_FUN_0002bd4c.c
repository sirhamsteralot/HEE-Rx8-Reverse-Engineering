/* ROM address: 0x0002bd4c; body bytes: 98; decompiled */

uint FUN_0002bd4c(void)

{
  uint uVar1;
  
  uVar1 = (uint)inferred_ram_ce32_ffffce32_ffffce32;
  if ((((uVar1 != 1) || (inferred_throttle_position_ffffad44 < 50.0)) || (inferred_coolant_temperature_ffffa98c < -40.0)) ||
     (((-10.0 <= inferred_coolant_temperature_ffffa98c || (uVar1 = (uint)engine_running_ffffa428, uVar1 != 0)) ||
      ((uVar1 = (uint)engine_injectors_off_ffffa42c, uVar1 != 1 || (uVar1 = (uint)DAT_ffffb420, uVar1 == 0)))))) {
    DAT_ffffbc28 = 0;
  }
  else {
    DAT_ffffbc28 = 1;
  }
  return uVar1;
}



/* ROM address: 0x000385f6; body bytes: 50; decompiled */

undefined4 * FUN_000385f6(void)

{
  undefined4 *puVar1;
  
  puVar1 = &vehicle_speed_ffffbbb4;
  if ((9.4 <= vehicle_speed_ffffbbb4) && (0.2188 <= engine_load_ffffc0b4)) {
    puVar1 = (undefined4 *)rx8_add_u16_saturate((int)DAT_ffffc4fc,1);
    DAT_ffffc4fc = (short)puVar1;
  }
  return puVar1;
}



/* ROM address: 0x0003825a; body bytes: 48; decompiled */

undefined4 * FUN_0003825a(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&DAT_0007a7f8;
  DAT_ffffc4c8 = inferred_coolant_temperature_ffffa98c;
  if (0x9ff < engine_running_timer_ffffa424) {
    puVar1 = &DAT_00038328;
    DAT_ffffc4c8 = DAT_ffffc4cc + DAT_ffffc4d0 * 0.099999994;
  }
  DAT_ffffc4cc = DAT_ffffc4c8;
  DAT_ffffc4d0 = 0.0;
  return puVar1;
}



/* ROM address: 0x000060c8; body bytes: 224; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000060c8 (224 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getSensorStuff__(void)

{
  byte bVar1;
  
  external_wdt_heartbeat_pulse();
  FUN_0000d3ce();
  FUN_0000a4f0();
  FUN_00009f48();
  FUN_0000a2a8();
  external_wdt_heartbeat_pulse();
  FUN_00005f18();
  external_wdt_heartbeat_pulse();
  FUN_00007070();
  adc_scan_sweep_all_channels();
  vehicle_inputs_poll_pfdr_phdr();
  FUN_00007280();
  FUN_000074ac();
  bVar1 = ATUII_TIOR3A_B;
  ATUII_TIOR3A_B = bVar1 & 0x8f | 0x60;
  ATUII_GR3B_W = 0;
  bVar1 = ATUII_TIOR3B_B;
  ATUII_TIOR3B_B = bVar1 & 0xf8 | 6;
  ATUII_GR3C_W = 0;
  bVar1 = ATUII_TIOR3B_B;
  ATUII_TIOR3B_B = bVar1 & 0x8f | 0x60;
  ATUII_GR3D_W = 0;
  bVar1 = ATUII_TIOR4A_B;
  ATUII_TIOR4A_B = bVar1 & 0xf8 | 6;
  ATUII_GR4A_W = 0;
  bVar1 = ATUII_TIOR4B_B;
  ATUII_TIOR4B_B = bVar1 & 0x8f | 0x60;
  ATUII_GR4D_W = 0;
  FUN_0000b4ec();
  FUN_0000bda0();
  FUN_00007330();
  FUN_00006372();
  maf_sensor_scaling();
  FUN_00007290();
  pedal_adc_raw_to_volts();
  FUN_00007398();
  FUN_0000d13c();
  FUN_0000b398();
  ref_getRearO2Voltage();
  ref_fuelingInit__();
  FUN_0000d70a();
  ref_misfireDetectInit_();
  ref_knockFunctionInit();
  FUN_0000cf56();
  FUN_000081a8();
  ref_ignitionDwellOutputInit();
  ch7d_pwm_off_init();
  FUN_0000a8dc();
  external_wdt_heartbeat_pulse();
  eeprom_mirror_magic_init();
  FUN_0001102a();
  external_wdt_heartbeat_pulse();
  ref_setRegisters();
  FUN_00009f0c(1);
  ref_taskEndRoutine_();
  return;
}



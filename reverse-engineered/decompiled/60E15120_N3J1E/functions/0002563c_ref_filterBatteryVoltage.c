/* ROM address: 0x0002563c; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025ec4 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_filterBatteryVoltage(void)

{
  DAT_ffffb594 = rx8_first_order_filter(inferred_battery_voltage_ffffb590,DAT_ffffb594,0.5,1e-05);
  return;
}



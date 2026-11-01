/* ROM address: 0x000598a8; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058060 (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_calcBatteryRelatedFaults__(void)

{
  if (((engine_stopped_latch_ffffa41c == '\x01') && (inferred_ram_cdd8_ffffcdd8_ffffcdd8 == '\0')) && (DAT_ffffd271 == '\0')) {
    DAT_ffffd25e = 1;
  }
  else {
    DAT_ffffd25e = 0;
  }
  if (((engine_stopped_latch_ffffa41c == '\0') && (inferred_ram_cdd8_ffffcdd8_ffffcdd8 == '\0')) &&
     ((DAT_ffffd271 == '\0' && (cranking_active_ffffaa62_ffffaa62 == '\x01')))) {
    DAT_ffffd25f = 1;
  }
  else {
    DAT_ffffd25f = 0;
  }
  if (((engine_stopped_latch_ffffa41c != '\x01') || (inferred_battery_voltage_ffffb590 <= 20.0)) || (14.60938 <= inferred_battery_voltage_ffffb590)) {
    DAT_ffffd260 = 0;
  }
  else {
    DAT_ffffd260 = 1;
  }
  return engine_stopped_latch_ffffa41c;
}



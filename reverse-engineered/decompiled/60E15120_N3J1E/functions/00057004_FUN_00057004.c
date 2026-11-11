/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x16f0: Tire Size. Dispatch identifier match; logger meaning is definition-derived.
 * RX8Defs diagnostic chain suggests RAM 0xffffd380 = tire_revolutions_per_mile. Direct C dataflow to handler 0x00057004; semantic candidate, not a recovered original symbol.
 */
/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid16f0_tire_revolutions_per_mile [high]: dispatch record 0x5f3d0 -> handler verified in ROM bytes + function_index; tire_revolutions_per_mile_ffffd380 raw u16 (logger 0x2216f0)
 */
/* ROM address: 0x00057004; body bytes: 14; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3d0. Table purpose inferred from
   neighboring code. */

void diag22_pid16f0_tire_revolutions_per_mile(undefined4 param_1)

{
  diag_append_u16_be(param_1,(int)tire_revolutions_per_mile_ffffd380);
  return;
}



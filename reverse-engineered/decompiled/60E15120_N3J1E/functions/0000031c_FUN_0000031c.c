/* [CROSS-ECU / RX8DEFS REVIEW]
 * service_wdt_overflow_and_toggle_pb15 [behavior_verified_role_candidate]: On WDT status bit 0x80, writes keyed value 0xa53c then toggles PBDR bit15. Matches external-watchdog heartbeat idiom documented by npkern; external chip/pin routing remains unverified. Boot-path evidence, not yet the running-engine heartbeat.
 */
/* ROM address: 0x0000031c; body bytes: 28; decompiled */

byte service_wdt_overflow_and_toggle_pb15(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = WDT_TCSR_RW__B;
  if ((bVar1 & 0x80) != 0) {
    Ramffffec10 = 0xa53c;
    uVar2 = PBDR_W;
    PBDR_W = uVar2 ^ 0x8000;
  }
  return bVar1;
}



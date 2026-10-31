/* [CROSS-ECU / RX8DEFS REVIEW]
 * service_wdt_overflow_toggle_pb15_and_count [behavior_verified_role_candidate]: Same PB15 toggle with a saturating event counter. Existing name checkWatchdogForOverflowandReset overstates reset behavior: the visible action is servicing/toggling, not issuing a reset.
 */
/* ROM address: 0x000011cc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000011cc (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

int service_wdt_overflow_toggle_pb15_and_count(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = WDT_TCSR_RW__B;
  if ((bVar1 & 0x80) != 0) {
    Ramffffec10 = 0xa53c;
    uVar2 = PBDR_W;
    PBDR_W = uVar2 ^ 0x8000;
    if (DAT_ffffdfa0._0_2_ != -1) {
      DAT_ffffdfa0._0_2_ = DAT_ffffdfa0._0_2_ + 1;
    }
  }
  return (int)DAT_ffffdfa0._0_2_;
}



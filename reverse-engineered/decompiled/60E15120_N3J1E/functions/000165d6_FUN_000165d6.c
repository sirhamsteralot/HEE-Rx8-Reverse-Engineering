/* [ADDITIONAL SOURCE REVIEW]
 * idle_ac_clutch_gate [medium]: 0xffffa8bc = 0 when (bd69==0 && a8bf) or engine-running timer < 0x80 or flags 0xffffbbb8/a7b6/c5e6/c5db/c5d7/c61e set; else 1; mirrors bd69 into a8bf. Called from 0x167c0 via pool 0x168bc.
 * RAM 0xffffbd69 ac_clutch_on (uint8): Set by 0x2e9a4 under a gating chain (engine-running timer 0xffffa424, injectors-off 0xffffa42c, rpm < 7800, coolant < 118 C, flags bd72/bd73/bd76/bd92/bd96/bd97/bd98/0xffffc5e6); adjacent to ref_calculateACClutchOn__ 0x2e89c; consumed as A/C-clutch select in the idle chain (0x16900/0x165d6/0x14944).
 * RAM 0xffffbbb8 vehicle_not_moving (uint8): Set by 0x2b156 when vspeed <= 4 km/h (hyst 5); read in the idle A/C clutch gate 0x165d6 (pool 0x166ee at 0x16626).
 */
/* ROM address: 0x000165d6; body bytes: 120; decompiled */

void candidate_idle_ac_clutch_gate(void)

{
  if ((ac_clutch_on_ffffbd69 == '\0') && (DAT_ffffa8bf == '\x01')) {
    DAT_ffffa8bc = 0;
  }
  else if (((engine_running_timer_ffffa424 < 0x80) ||
           (((vehicle_not_moving_ffffbbb8 != '\x01' || (DAT_ffffa7b6 != '\0')) || (DAT_ffffc5e6 != '\0')))) ||
          (((DAT_ffffc5db != '\0' || (DAT_ffffc5d7 != '\0')) || (DAT_ffffc61e != '\0')))) {
    DAT_ffffa8bc = 0;
  }
  else {
    DAT_ffffa8bc = 1;
  }
  DAT_ffffa8bf = ac_clutch_on_ffffbd69;
  return;
}



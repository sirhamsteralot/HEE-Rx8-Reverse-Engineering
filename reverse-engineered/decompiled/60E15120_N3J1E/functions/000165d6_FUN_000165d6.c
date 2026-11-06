/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbbb8 vehicle_not_moving (uint8): Set by 0x2b156 when vspeed <= 4 km/h (hyst 5); read in the idle A/C clutch gate 0x165d6 (pool 0x166ee at 0x16626).
 */
/* ROM address: 0x000165d6; body bytes: 120; decompiled */

void FUN_000165d6(void)

{
  if ((DAT_ffffbd69 == '\0') && (DAT_ffffa8bf == '\x01')) {
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
  DAT_ffffa8bf = DAT_ffffbd69;
  return;
}



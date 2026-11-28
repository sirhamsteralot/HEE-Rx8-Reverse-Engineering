/* [ADDITIONAL SOURCE REVIEW]
 * misfire_high_rpm_flag [high]: DAT_ffffba70 = (5000.0 <= engine_speed_rpm_ffffb548); DAT_ffffba60 = (ba70 != 0); DAT_ffffba5e = 9, DAT_ffffba5f = 0xc (mov #imm at 0x280b8/0x280bc). Called from 0x287aa.
 * RAM 0xffffba60 misfire_high_rpm_active (uint8): Set by 0x280be when rpm >= 5000.0 (ba70); selects the coolant-corrected x 3D-threshold form in 0x2853c/0x28648.
 */
/* ROM address: 0x000280be; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028a06 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 misfire_high_rpm_flag(void)

{
  if (5000.0 <= engine_speed_rpm_ffffb548) {
    if (5000.0 <= engine_speed_rpm_ffffb548) {
      DAT_ffffba70 = '\x01';
    }
  }
  else {
    DAT_ffffba70 = '\0';
  }
  misfire_high_rpm_active_ffffba60 = DAT_ffffba70 != '\0';
  DAT_ffffba5f = 0xc;
  DAT_ffffba5e = 9;
  return 0xc;
}



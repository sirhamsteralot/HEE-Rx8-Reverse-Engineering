/* [ADDITIONAL SOURCE REVIEW]
 * secondary_air_solenoid_control [high]: Writes PEDR_W bit 0x100 (PE8, pkg pin 17) from diag-checked request: load > 0.8 (hyst 0.75, a961), RPM > 4000 (hyst 3900, a962), condition (bf6c && !a961 && !a962) || d26e; override via ref_diagCheckSecondaryAirRequest (0x5cf7c) -> a960. Harness: secondary air injection solenoid PCM 1O. Called from 0x117ac (task 0x6584 chain).
 * RAM 0xffffa960 secondary_air_request_final (uint8): diag-checked secondary-air solenoid request (PE8).
 * RAM 0xffffa961 sec_air_load_high (uint8): load > 0.8 (hyst 0.75).
 * RAM 0xffffa962 sec_air_rpm_high (uint8): RPM > 4000 (hyst 3900).
 */
/* ROM address: 0x000187b8; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000193b4 (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 secondary_air_solenoid_control(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  char cStack_8;
  
  if (engine_load_ffffc0b4 <= 0.8) {
    if (engine_load_ffffc0b4 <= 0.75) {
      sec_air_load_high_ffffa961 = '\0';
    }
  }
  else {
    sec_air_load_high_ffffa961 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 <= 4000.0) {
    if (engine_speed_rpm_ffffb548 <= 3900.0) {
      sec_air_rpm_high_ffffa962 = '\0';
    }
  }
  else {
    sec_air_rpm_high_ffffa962 = '\x01';
  }
  if ((((secondary_air_pump_request_ffffbf6c == '\x01') && (sec_air_load_high_ffffa961 == '\0')) && (sec_air_rpm_high_ffffa962 == '\0')) ||
     (DAT_ffffd26e == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  cStack_8 = candidate_secondary_air_diag_override(uVar1);
  secondary_air_request_final_ffffa960 = cStack_8;
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x100,cStack_8 == '\x01');
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}



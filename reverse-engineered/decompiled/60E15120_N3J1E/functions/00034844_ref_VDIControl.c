/* [ADDITIONAL SOURCE REVIEW]
 * vdi_solenoid_control [high]: Writes PDDR_W 0xfffff746 bit 0x20 (PD5, pkg pin 254; PD5/TIO1F alternate) after diag override ref_diagControlVDI. On = RPM >= 7250 (hysteresis 7062). Harness: VDI solenoid PCM 1W. Reached from 0x11744 -> 0x348ea.
 * RAM 0xffffc1c0 vdi_command (uint8): RPM 7062/7250 hysteresis -> ref_diagControlVDI -> PEDR PD5.
 */
/* ROM address: 0x00034844; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00034f64 (126 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate VDI control. Firmware fact: writes mask 0x0020 of 0xfffff746 (PDDR_W, PD5 = pkg pin 254) after hysteresis and diagnostic override. pinout v3: VDI solenoid control at PCM 1W, wire L/B (confirmed). Chip-pin -> terminal routing still board-level unresolved. */

void vdi_solenoid_control(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  iVar1 = (int)vdi_command_ffffc1c0;
  if (engine_speed_rpm_ffffb548 < 7250.0) {
    if (engine_speed_rpm_ffffb548 < 7062.0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  vdi_command_ffffc1c0 = candidate_vdi_diag_override(iVar1);
  if (vdi_command_ffffc1c0 == '\x01') {
    ref_setSR_PARAM(auStack_14,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff746,0x20,1);
  }
  else {
    ref_setSR_PARAM(&local_18,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff746,0x20,0);
    auStack_14[0] = local_18;
  }
  FUN_00002064(auStack_14[0]);
  return;
}



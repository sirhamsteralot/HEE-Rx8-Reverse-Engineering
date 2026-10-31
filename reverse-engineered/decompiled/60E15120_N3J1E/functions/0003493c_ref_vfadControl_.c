/* [ADDITIONAL SOURCE REVIEW]
 * vfad_solenoid_control [high]: Writes PEDR_W bit 0x400 (PE10, pkg pin 19) after diag override ref_diagControlVFADMAYBE. On = RPM >= 5250 (hysteresis 5062). Harness: VFAD solenoid PCM 5Z (high-power only). Reached from 0x11744 -> 0x34916.
 * RAM 0xffffc1c4 vfad_command (uint8): RPM 5062/5250 hysteresis -> ref_diagControlVFADMAYBE -> PEDR PE10.
 */
/* ROM address: 0x0003493c; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003505c (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

void vfad_solenoid_control(void)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  iVar1 = (int)vfad_command_ffffc1c4;
  if (engine_speed_rpm_ffffb548 < 5250.0) {
    if (engine_speed_rpm_ffffb548 < 5062.0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  vfad_command_ffffc1c4 = candidate_vfad_diag_override(iVar1);
  if (vfad_command_ffffc1c4 == '\x01') {
    ref_setSR_PARAM(auStack_18,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x400,1);
  }
  else {
    ref_setSR_PARAM(&local_1c,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x400,0);
    auStack_18[0] = local_1c;
  }
  FUN_00002064(auStack_18[0]);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_attack [high]: Knock retard target: disabled (a73d==0) -> 0; sensors unhealthy (a73e==0) -> tbl 0x6afa4(RPM); activation edge (a74c==0 && a73c==1) -> tbl 0x6afb8(learned retard); active && attack condition (c05c==1) -> -1.0 deg/cycle (retard is negative, clamped <= 0). Writes a744, then clamped a734 = 0x13bd2(result), mirror a738.
 * RAM 0xffffa744 knock_recovery_target (float): Attack/recovery target written by 0x13a60: 0 when disabled, tbl 0x6afa4 when sensors unhealthy, tbl 0x6afb8 on activation edge, else previous retard.
 * RAM 0xffffa74c knock_active_previous (uint8): Previous a73c; activation-edge detection (a74c==0 && a73c==1).
 * RAM 0xffffc05c knock_attack_condition (uint8): Set by 0x33970: knock latched && running && timing not already deeply retarded; selects -1.0 deg/cycle attack in 0x13a60.
 */
/* ROM address: 0x00013a60; body bytes: 166; decompiled */

void knock_retard_attack(void)

{
  char cVar1;
  float fVar2;
  undefined4 uVar3;
  
  cVar1 = knock_active_ffffa73c;
  if (knock_enable_ffffa73d == '\0') {
    fVar2 = 0.0;
  }
  else if (knock_sensors_healthy_ffffa73e == '\0') {
    fVar2 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_knock_recovery_target_0006afa4);
    knock_recovery_target_ffffa744 = fVar2;
  }
  else {
    fVar2 = knock_retard_ffffa734;
    if (knock_active_previous_ffffa74c == '\0') {
      if (knock_active_ffffa73c == '\x01') {
        uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8038);
        fVar2 = (float)lookup_2d_descriptor_scaled(uVar3,&tbl_knock_learned_retard_scale_0006afb8);
        knock_recovery_target_ffffa744 = fVar2;
      }
    }
    else if ((knock_active_ffffa73c == '\x01') && (knock_attack_condition_ffffc05c == '\x01')) {
      fVar2 = knock_retard_ffffa734 - 1.0;
    }
  }
  knock_retard_ffffa734 = (float)knock_retard_clamp(fVar2);
  knock_retard_mirror_ffffa738 = knock_retard_ffffa734;
  knock_active_previous_ffffa74c = cVar1;
  return;
}



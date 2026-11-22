/* [ADDITIONAL SOURCE REVIEW]
 * throttle_servo_override [high]: Servo/homing override in batch 0x22f86. dir b400 = (b4b0 >= readValue_float(0xffff807c, default 15.0f @0x6f438)+0.5f @0x747c4, band 0x747c8=0.0f); mode byte ccbc; duty b3f8: mode!=1 -> 0.0; mode==1 && b401==0 -> min(b410+learned, learned+0.5f @0x747b8) while b401==0; else decay max(5.0f @0x747bc, b3f8-0.05f @0x747c0) while the word counters b3fc/b3fe exceed 2 (0x747b4/0x747b6). Pools 0x22e9e-0x22f18 verified: 0x22ea0=0xb4b0, 0x22ea2=0xccbc, 0x22ea4=0xb3f8, 0x22ea6=0xb410, 0x22ebc=0xffffb400, 0x22ec0=0xffffb3fc, 0x22ec4=0xffffb3fe, 0x22ec8/0x22f18=0xffffb401.
 * RAM 0xffffb3f8 throttle_servo_override_duty (float): Servo/homing override duty float written by 0x22db4 (pool 0x22ea4=0xb3f8); 0.0 when mode ccbc!=1; decay max(5.0, b3f8-0.05) with counters b3fc/b3fe; read by 0x231f0 (ccbc branch) and by its own decay path.
 * RAM 0xffffb400 throttle_servo_direction (uint8): Direction byte written by 0x22db4 (pool 0x22ebc=0xffffb400): 1 when target b4b0 >= learned 0xffff807c + 0.5f. No other reader found in ROM (whole-ROM pool scan).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022db4; body bytes: 274; decompiled */

uint throttle_servo_override(void)

{
  byte snapshot_throttle_servo_mode_ffffccbc;
  uint uVar2;
  float fVar3;
  float fVar4;
  float arg0;
  
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  snapshot_throttle_servo_mode_ffffccbc = throttle_servo_mode_ffffccbc;
  arg0 = (fVar3 + 0.5) - 0.0;
  if (DAT_ffffb4b0 < fVar3 + 0.5) {
    if (DAT_ffffb4b0 < arg0) {
      throttle_servo_direction_ffffb400 = '\0';
    }
  }
  else {
    throttle_servo_direction_ffffb400 = '\x01';
  }
  uVar2 = (uint)throttle_servo_mode_ffffccbc;
  if (uVar2 == 1) {
    if (DAT_ffffb401 == '\0') {
      fVar4 = fVar3 + 0.5;
      if (DAT_ffffb4b0 < fVar3 + 0.5) {
        fVar4 = rx8_min_float(arg0,inferred_ram_b410_ffffb410_ffffb410 + fVar3);
      }
    }
    else {
      fVar4 = throttle_servo_override_duty_ffffb3f8;
      if (throttle_servo_direction_ffffb400 == '\x01') {
        if (1 < DAT_ffffb3fc) {
          fVar4 = rx8_max_float(5.0,throttle_servo_override_duty_ffffb3f8 - 0.05);
          DAT_ffffb3fc = 0;
        }
      }
      else if (1 < DAT_ffffb3fe) {
        fVar4 = rx8_max_float(5.0,throttle_servo_override_duty_ffffb3f8 - 0.05);
        DAT_ffffb3fe = 0;
      }
    }
  }
  else {
    throttle_servo_override_duty_ffffb3f8 = 0.0;
    fVar4 = throttle_servo_override_duty_ffffb3f8;
  }
  throttle_servo_override_duty_ffffb3f8 = fVar4;
  if (uVar2 == 1) {
    if (throttle_servo_direction_ffffb400 != '\x01') {
      DAT_ffffb3fc = 0;
      uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb3fe,1);
      DAT_ffffb3fe = (short)uVar2;
      DAT_ffffb401 = snapshot_throttle_servo_mode_ffffccbc;
      return uVar2;
    }
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb3fc,1);
    DAT_ffffb3fc = (ushort)uVar2;
  }
  else {
    DAT_ffffb3fc = 0;
  }
  DAT_ffffb3fe = 0;
  DAT_ffffb401 = snapshot_throttle_servo_mode_ffffccbc;
  return uVar2;
}



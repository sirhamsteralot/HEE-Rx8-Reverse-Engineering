/* [ADDITIONAL SOURCE REVIEW]
 * idle_trim_integrator [medium]: Long-term idle trim: reads learned trim floats 0xffff8040/0xffff8048 (mov.w pools 0x16260/0x16262, sign-extended) via 0x3dcd0/0x3dc22 ref_readValue_float_DEFAULTVAL_ADDRESS, nudges by 1e-5 toward the sign of 0xffffa7a8 when learn flag 0xffffa890==1 (pool 0x16264 at 0x161cc), clamps to [-0.12, 0.12], writes back via ref_updateMemoryAtAddress_float; 0xffffb534/0xffffb53c select which cell. Called from 0x167c0 via pool 0x168c8.
 * RAM 0xffffa890 idle_trim_learn_active (uint8): Learn-enable flag computed by 0x15ffc (counters a892/a894 reload 0x138; coolant/IAT/error gates); gates the trim integration in 0x1617e (read via pool 0x16264 at 0x161cc).
 */
/* ROM address: 0x0001617e; body bytes: 408; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000161a4) */

undefined4 candidate_idle_trim_integrator(void)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  
  uVar5 = 0;
  fVar4 = DAT_ffffa7a8;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8040);
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar5,&DAT_ffff8048);
  if (automatic_transmission_ffffb534 == '\0') {
    if (idle_trim_learn_active_ffffa890 == '\x01') {
      if (at_drive_range_engaged_ffffb53c == '\0') {
        if (fVar4 < 0.005) {
          if (fVar4 <= -0.005) {
            fVar2 = fVar2 - 1e-05;
          }
        }
        else {
          fVar2 = fVar2 + 1e-05;
        }
        fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
        ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff8040);
        fVar6 = fVar3 + 0.03;
        fVar2 = fVar3 - 0.03;
        fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar5,&DAT_ffff8040);
        if (fVar4 <= fVar6) {
          if (fVar4 < fVar2) {
            fVar3 = fVar4 + 0.03;
          }
        }
        else {
          fVar3 = fVar4 - 0.03;
        }
        fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
        sVar1 = -0x7fb8;
      }
      else {
        if (fVar4 < 0.005) {
          if (fVar4 <= -0.005) {
            fVar3 = fVar3 - 1e-05;
          }
        }
        else {
          fVar3 = fVar3 + 1e-05;
        }
        fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
        ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff8048);
        fVar3 = fVar2 + 0.03;
        fVar6 = fVar2 - 0.03;
        fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar5,&DAT_ffff8048);
        if (fVar4 <= fVar3) {
          if (fVar4 < fVar6) {
            fVar2 = fVar4 + 0.03;
          }
        }
        else {
          fVar2 = fVar4 - 0.03;
        }
        fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
        sVar1 = -0x7fc0;
      }
      uVar5 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,(int)sVar1);
    }
    else {
      fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
      ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff8040);
      fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
      uVar5 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff8048);
    }
  }
  else {
    if (idle_trim_learn_active_ffffa890 == '\x01') {
      if (fVar4 < 0.005) {
        if (fVar4 <= -0.005) {
          fVar2 = fVar2 - 1e-05;
        }
      }
      else {
        fVar2 = fVar2 + 1e-05;
      }
    }
    fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
    uVar5 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff8040);
  }
  return uVar5;
}



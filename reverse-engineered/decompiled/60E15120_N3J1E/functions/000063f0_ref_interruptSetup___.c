/* ROM address: 0x000063f0; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000063f0 (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_interruptSetup___(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  FUN_0000a3ac();
  FUN_00006a4c();
  maf_sensor_scaling();
  FUN_0000acfc();
  FUN_0000b602();
  FUN_000114b0();
  DAT_ffff9f52 = DAT_ffff9f52 + 1;
  ref_setSR_PARAM(local_8,0xe0);
  if (DAT_ffff9f52 < DAT_ffff9f54) {
    if (DAT_ffff9f58 <= DAT_ffff9f52) {
      ref_setRegister_REG_BIT_VAL(0xfffff746,0x10,0);
    }
  }
  else {
    DAT_ffff9f52 = 0;
    DAT_ffff9f58 = DAT_ffff9f5a;
    DAT_ffff9f54 = DAT_ffff9f56;
    if ((DAT_ffff9f5c == '\0') && (DAT_ffff9f5a != 0)) {
      ref_setRegister_REG_BIT_VAL(0xfffff746,0x10,1);
    }
  }
  FUN_00002064(local_8[0]);
  candidate_apv_pwm_service();
  uVar1 = ref_taskEndRoutine_();
  return uVar1;
}



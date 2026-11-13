/* ROM address: 0x000061a8; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000061a8 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_mainInit__(void)

{
  code *unaff_r14;
  
  FUN_0000d70a();
  ref_misfireDetectInit_();
  ref_knockFunctionInit();
  FUN_0000cf56();
  FUN_000081a8();
  ref_ignitionDwellOutputInit();
  FUN_0000b23c();
  FUN_0000a8dc();
  (*unaff_r14)();
  eeprom_mirror_magic_init();
  FUN_0001102a();
  (*unaff_r14)();
  ref_setRegisters();
  FUN_00009f0c(1);
  ref_taskEndRoutine_();
  return;
}



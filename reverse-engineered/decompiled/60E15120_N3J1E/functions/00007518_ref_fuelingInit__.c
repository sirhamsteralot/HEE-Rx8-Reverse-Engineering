/* ROM address: 0x00007518; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007518 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_fuelingInit__(void)

{
  ushort uVar1;
  
  FUN_000076b8();
  uVar1 = ATUII_TIER10_W;
  ATUII_TIER10_W = uVar1 & 0xfffb;
  DAT_ffff9fa3 = 1;
  DAT_ffff9fa4 = 0;
  DAT_ffff9fa5 = 0;
  DAT_ffff9fc0 = 0;
  DAT_ffff9fc4 = 0;
  DAT_ffff9fa2 = 0;
  ref_reInitCrankSensor__();
  FUN_00007bdc();
  FUN_00007b84();
  DAT_ffff9f96 = 0;
  DAT_ffff9fcb = 0;
  ref_crankSensorInit_();
  FUN_00007eb4();
  ref_engineSpeedInit();
  FUN_0000806a();
  return;
}



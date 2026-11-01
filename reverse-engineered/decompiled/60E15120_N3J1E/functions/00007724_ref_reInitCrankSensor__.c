/* ROM address: 0x00007724; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007724 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_reInitCrankSensor__(void)

{
  uint uVar1;
  
  DAT_ffff9f95 = 0x24;
  DAT_ffff9fc1 = 0;
  crank_icr10ah_sample_ffff9fb0 = 0xffffffff;
  DAT_ffff9fc2 = 0;
  DAT_ffff9fbc = 0;
  DAT_ffff9fc5 = 0;
  DAT_ffff9fa1 = 0;
  FUN_00007b58();
  if (DAT_ffff9fc0 == 1) {
    DAT_ffff9fc0 = 0;
    if (DAT_ffff9fa3 != '\x02') {
      ref_crankSensorInit_();
    }
    uVar1 = FUN_00007b84();
    return uVar1;
  }
  return (uint)DAT_ffff9fc0;
}



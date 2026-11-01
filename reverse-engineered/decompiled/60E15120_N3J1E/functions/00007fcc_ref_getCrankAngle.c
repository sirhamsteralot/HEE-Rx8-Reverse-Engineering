/* ROM address: 0x00007fcc; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007fcc (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_getCrankAngle(byte param_1)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  
  DAT_ffff9f84 = crank_period_last_ffff9fa8;
  DAT_ffff9f9c = crank_icr0ah_sample_ffff9fb8;
  DAT_ffff9f98 = (float)param_1 * 30.0 + -5.0;
  if (DAT_ffff9f98 < 0.0) {
    DAT_ffff9f98 = DAT_ffff9f98 + 720.0;
  }
  DAT_ffff9fe9 = DAT_ffff9fe9 + 1;
  if (5 < DAT_ffff9fe9) {
    DAT_ffff9fe9 = 0;
  }
  puVar1 = &DAT_ffff9fd0;
  (&DAT_ffff9fd0)[DAT_ffff9fe9] = crank_period_last_ffff9fa8;
  if (DAT_ffff9fe8 != 0xff) {
    DAT_ffff9fe8 = DAT_ffff9fe8 + 1;
  }
  if (5 < DAT_ffff9fe8) {
    crank_period_accumulator_ffff9f88 = 0;
    bVar3 = 0;
    piVar4 = &DAT_ffff9fd0;
    do {
      bVar3 = bVar3 + 1;
      iVar2 = *piVar4;
      piVar4 = piVar4 + 1;
      crank_period_accumulator_ffff9f88 = crank_period_accumulator_ffff9f88 + iVar2;
    } while (bVar3 < 6);
    puVar1 = &DAT_000080d4;
    engine_speed_rpm_raw_ffff9f80 = 1.2e+08 / (float)crank_period_accumulator_ffff9f88;
  }
  return puVar1;
}



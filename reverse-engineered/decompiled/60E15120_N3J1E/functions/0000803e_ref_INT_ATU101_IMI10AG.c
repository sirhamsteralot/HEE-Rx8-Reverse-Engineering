/* ROM address: 0x0000803e; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000803e (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * crank_isr_compute_rpm(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &crank_period_ring_ffff9fd0;
  do {
    param_4 = param_4 + 1;
    iVar1 = *piVar2;
    piVar2 = piVar2 + 1;
    param_3 = param_3 + iVar1;
  } while ((int)(param_4 & 0xff) < param_1);
  crank_period_accumulator_ffff9f88 = param_3;
  engine_speed_rpm_raw_ffff9f80 = 1.2e+08 / (float)param_3;
  return &DAT_000080d4;
}



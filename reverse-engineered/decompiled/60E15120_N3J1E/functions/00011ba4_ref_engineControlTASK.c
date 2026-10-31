/* ROM address: 0x00011ba4; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011c1c (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_engineControlTASK(byte param_1)

{
  uint uVar1;
  
  FUN_000197be();
  FUN_00038dca();
  fueling_main_task();
  ignition_timing_main_task();
  FUN_00016c88();
  uVar1 = (uint)param_1;
  if (uVar1 == 0) {
    FUN_00020f88();
  }
  if (uVar1 == 2) {
    uVar1 = FUN_00020f88();
    return uVar1;
  }
  return uVar1;
}



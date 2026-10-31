/* ROM address: 0x0000a156; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a156 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a156(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  uVar1 = ref_osTaskScheduler(1,9,local_8);
  return uVar1;
}



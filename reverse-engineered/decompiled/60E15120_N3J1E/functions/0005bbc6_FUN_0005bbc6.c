/* ROM address: 0x0005bbc6; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a3b6 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005bbc6(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0) {
    DAT_ffffd30c = 0;
    uVar1 = ref_handleCANReset();
    return uVar1;
  }
  if (uVar1 != 1) {
    return uVar1;
  }
  DAT_ffffd30c = 1;
  uVar1 = FUN_0000dae8();
  return uVar1;
}



/* ROM address: 0x00003ad8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003ad8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003ad8(char param_1)

{
  undefined4 uVar1;
  uint in_sr;
  undefined1 local_8 [4];
  uint local_4;
  
  local_4 = in_sr & 0xfffffffe | (uint)(param_1 != '\0');
  if ((param_1 != '\0') != 0) {
    return 0;
  }
  DAT_ffff7660 = local_8;
  DAT_ffff7640 = 0x100;
  uVar1 = FUN_00003e10();
  return uVar1;
}



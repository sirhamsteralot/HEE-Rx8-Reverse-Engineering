/* ROM address: 0x00067732; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066022 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067732(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8f98;
  (&DAT_ffff8e8d)[uVar1 * 0x28] = 1;
  (&DAT_ffff8e80)[uVar1 * 10] = *param_1;
  (&DAT_ffff8e84)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8e88)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8e8c)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}



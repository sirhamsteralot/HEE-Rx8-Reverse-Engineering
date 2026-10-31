/* ROM address: 0x00067826; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066116 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067826(short param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 1;
    }
  }
  *param_2 = (&DAT_ffff8e90)[uVar1 * 10];
  param_2[1] = (&DAT_ffff8e94)[uVar1 * 10];
  param_2[2] = (&DAT_ffff8e98)[uVar1 * 10];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8e9c)[uVar1 * 0x28];
  return 0;
}



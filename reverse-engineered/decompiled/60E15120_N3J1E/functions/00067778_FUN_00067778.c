/* ROM address: 0x00067778; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066068 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067778(short param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1)) ||
         ((&DAT_ffff8e8d)[uVar1 * 0x28] != '\x01'))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 1;
    }
  }
  *param_2 = (&DAT_ffff8e80)[uVar1 * 10];
  param_2[1] = (&DAT_ffff8e84)[uVar1 * 10];
  param_2[2] = (&DAT_ffff8e88)[uVar1 * 10];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8e8c)[uVar1 * 0x28];
  return 0;
}



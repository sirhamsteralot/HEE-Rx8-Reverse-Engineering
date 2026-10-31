/* ROM address: 0x00063b60; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062450 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063b60(char param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while (((&DAT_ffff890e)[uVar1 * 0x34] != param_1 || (DAT_ffff8d4c._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  iVar2 = uVar1 * 0x34;
  *param_2 = (&DAT_ffff8908)[uVar1 * 0x1a];
  param_2[1] = (&DAT_ffff890a)[uVar1 * 0x1a];
  param_2[2] = (&DAT_ffff890c)[uVar1 * 0x1a];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff890e)[iVar2];
  *(undefined1 *)((int)param_2 + 7) = (&DAT_ffff890f)[iVar2];
  *(undefined1 *)(param_2 + 4) = (&DAT_ffff8910)[iVar2];
  return 1;
}



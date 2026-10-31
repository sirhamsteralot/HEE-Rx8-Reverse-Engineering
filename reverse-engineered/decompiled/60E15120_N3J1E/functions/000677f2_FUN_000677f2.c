/* ROM address: 0x000677f2; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000660e2 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000677f2(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8f98;
  (&DAT_ffff8e90)[uVar1 * 10] = *param_1;
  (&DAT_ffff8e94)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8e98)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8e9c)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}



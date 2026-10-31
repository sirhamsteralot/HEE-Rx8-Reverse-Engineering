/* ROM address: 0x000107d4; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000107c8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000107d4(int param_1)

{
  int iVar1;
  
  param_1 = (uint)DAT_ffffa5d4 * 0x1e0000 - param_1;
  iVar1 = param_1 + -0x50000;
  if (iVar1 < 0x2d00000) {
    if (iVar1 < 0) {
      iVar1 = param_1 + 0x2cb0000;
    }
  }
  else {
    iVar1 = param_1 + -0x2d50000;
  }
  return iVar1;
}



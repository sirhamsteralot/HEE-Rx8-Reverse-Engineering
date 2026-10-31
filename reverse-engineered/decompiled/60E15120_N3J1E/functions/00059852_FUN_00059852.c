/* ROM address: 0x00059852; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005800a (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00059852(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd25a;
  if (uVar1 == 1) {
    uVar1 = thunk_FUN_000601b2();
    DAT_ffffd25b = 0;
    DAT_ffffd25a = 0;
  }
  return uVar1;
}



/* ROM address: 0x0000a438; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a438 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000a438(int param_1,undefined4 param_2)

{
  if (*(int *)(&DAT_ffff8004 + (uint)DAT_ffff802d * 8) != param_1) {
    if (DAT_ffff802d < 4) {
      DAT_ffff802d = DAT_ffff802d + 1;
    }
    else {
      DAT_ffff802d = 0;
    }
    *(int *)(&DAT_ffff8004 + (uint)DAT_ffff802d * 8) = param_1;
    *(undefined4 *)(&DAT_ffff8008 + (uint)DAT_ffff802d * 8) = param_2;
    DAT_ffff802c = 0;
  }
  return;
}



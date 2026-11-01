/* ROM address: 0x000336aa; body bytes: 42; decompiled */

void FUN_000336aa(void)

{
  DAT_ffffc050 = DAT_ffffc050 + 1;
  if (0x18 < DAT_ffffc050) {
    FUN_00033706();
    FUN_000336dc();
    DAT_ffffc050 = 0;
  }
  return;
}



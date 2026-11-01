/* ROM address: 0x000189d4; body bytes: 58; decompiled */

void FUN_000189d4(void)

{
  if (DAT_ffffa974 < 8) {
    if (DAT_ffffa974 < 7) {
      FUN_000182ba(2);
      DAT_ffffa97b = 0x10;
    }
    else {
      FUN_000182ba(4);
      DAT_ffffa97b = 4;
    }
  }
  else {
    FUN_000182ba(3);
    DAT_ffffa97b = 0x10;
  }
  return;
}



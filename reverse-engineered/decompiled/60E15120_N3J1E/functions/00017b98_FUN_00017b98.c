/* ROM address: 0x00017b98; body bytes: 58; decompiled */

void FUN_00017b98(void)

{
  if (DAT_ffffa8f4 < 8) {
    if (DAT_ffffa8f4 < 7) {
      FUN_000174b4(2);
      DAT_ffffa8fa = 0x10;
    }
    else {
      FUN_000174b4(4);
      DAT_ffffa8fa = 4;
    }
  }
  else {
    FUN_000174b4(3);
    DAT_ffffa8fa = 0x10;
  }
  return;
}



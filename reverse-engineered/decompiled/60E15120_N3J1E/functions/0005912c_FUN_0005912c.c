/* ROM address: 0x0005912c; body bytes: 56; decompiled */

void FUN_0005912c(void)

{
  if (engine_stopped_latch_ffffa41c == '\0') {
    DAT_ffffd240 = 0;
  }
  else if (DAT_ffffd243 == '\x01') {
    DAT_ffffd243 = '\0';
    DAT_ffffd242 = 1;
    DAT_ffffd240 = 0x249;
  }
  if (DAT_ffffd240 == 0) {
    DAT_ffffd242 = 0;
  }
  return;
}



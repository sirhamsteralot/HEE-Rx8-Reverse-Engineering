/* ROM address: 0x000128d8; body bytes: 88; decompiled */

void FUN_000128d8(void)

{
  if (DAT_ffffbc1c <= 0.0) {
    if (DAT_ffffa68c != 0) {
      DAT_ffffa68c = DAT_ffffa68c + -1;
    }
  }
  else {
    DAT_ffffa68c = 0xfa;
  }
  if ((DAT_ffffad90 == '\0') || (DAT_ffffa68c == 0)) {
    DAT_ffffa67c = 0;
  }
  else if (DAT_ffffa690 == '\x01') {
    DAT_ffffa67c = 1;
  }
  return;
}



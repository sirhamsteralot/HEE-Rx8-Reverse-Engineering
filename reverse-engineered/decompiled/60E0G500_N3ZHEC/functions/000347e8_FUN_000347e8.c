/* ROM address: 0x000347e8; body bytes: 88; decompiled */

void FUN_000347e8(void)

{
  if (DAT_ffffc100 != 0) {
    DAT_ffffc100 = DAT_ffffc100 + -1;
  }
  if (DAT_ffffadbc <= 71.4) {
    DAT_ffffc11a = 0;
  }
  else {
    DAT_ffffc11a = FUN_00002460((int)DAT_ffffc11a,1);
  }
  if (DAT_ffffb5aa == '\0') {
    DAT_ffffc11c = FUN_00002460((int)DAT_ffffc11c,1);
  }
  else {
    DAT_ffffc11c = 0;
  }
  return;
}



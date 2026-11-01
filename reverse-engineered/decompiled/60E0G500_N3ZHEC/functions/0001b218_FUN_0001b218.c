/* ROM address: 0x0001b218; body bytes: 72; decompiled */

void FUN_0001b218(void)

{
  if (DAT_ffffaa40 < 2.5) {
    if (DAT_ffffaa40 < 2.0) {
      DAT_ffffaadc = '\0';
    }
  }
  else {
    DAT_ffffaadc = '\x01';
  }
  if (DAT_ffffaadc == '\0') {
    DAT_ffffaad8 = FUN_00002460((int)DAT_ffffaad8,1);
  }
  else {
    DAT_ffffaad8 = 0;
  }
  return;
}



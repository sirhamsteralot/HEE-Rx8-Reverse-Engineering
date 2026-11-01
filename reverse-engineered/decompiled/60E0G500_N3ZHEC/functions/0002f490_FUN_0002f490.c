/* ROM address: 0x0002f490; body bytes: 204; decompiled */

void FUN_0002f490(void)

{
  if (DAT_ffffb5b8 < 600.0) {
    if (DAT_ffffb5b8 < 400.0) {
      DAT_ffffbe00 = '\0';
    }
  }
  else {
    DAT_ffffbe00 = '\x01';
  }
  if (DAT_ffffb5b8 < 7800.0) {
    if (DAT_ffffb5b8 < 7300.0) {
      DAT_ffffbe01 = '\0';
    }
  }
  else {
    DAT_ffffbe01 = '\x01';
  }
  if (DAT_ffffbdd5 == '\0') {
    if ((((4 < DAT_ffffbdf2) || (DAT_ffffbe00 == '\0')) || (DAT_ffffbe01 == '\x01')) ||
       ((DAT_ffffbdde == '\x01' || (DAT_ffffbddf == '\x01')))) {
      DAT_ffffbdd4 = 0;
    }
    DAT_ffffbdf0 = 0;
    DAT_ffffbdf2 = FUN_00002460((int)(short)DAT_ffffbdf2,1);
  }
  else {
    if (0xd < DAT_ffffbdf0) {
      DAT_ffffbdd4 = 1;
    }
    DAT_ffffbdf0 = FUN_00002460((int)(short)DAT_ffffbdf0,1);
    DAT_ffffbdf2 = 0;
  }
  return;
}



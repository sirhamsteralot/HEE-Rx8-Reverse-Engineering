/* ROM address: 0x00039352; body bytes: 110; decompiled */

void FUN_00039352(void)

{
  if ((DAT_ffffc538 <= 40.0) || (DAT_ffffbc1c <= 40.0)) {
    DAT_ffffc573 = '\0';
  }
  else {
    DAT_ffffc573 = '\x01';
  }
  if (DAT_ffffc573 == '\x01') {
    DAT_ffffc558 = DAT_ffffc548 + DAT_ffffc558;
  }
  DAT_ffffc564 = rx8_max_float(DAT_ffffc564 + (DAT_ffffc538 - DAT_ffffaa10) * DAT_ffffc588,0.0);
  return;
}



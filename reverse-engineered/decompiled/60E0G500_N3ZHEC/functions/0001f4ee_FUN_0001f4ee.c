/* ROM address: 0x0001f4ee; body bytes: 148; decompiled */

undefined1 * FUN_0001f4ee(void)

{
  if (DAT_ffffaa88 < 1.0) {
    if (DAT_ffffaa88 < 0.39999998) {
      DAT_ffffb171 = '\0';
    }
  }
  else {
    DAT_ffffb171 = '\x01';
  }
  if (DAT_ffffaa88 < 9.0) {
    if (DAT_ffffaa88 < 8.4) {
      DAT_ffffb172 = '\0';
    }
  }
  else {
    DAT_ffffb172 = '\x01';
  }
  if (DAT_ffffaa88 < 22.0) {
    if (DAT_ffffaa88 < 21.4) {
      DAT_ffffb173 = '\0';
    }
  }
  else {
    DAT_ffffb173 = '\x01';
  }
  if (DAT_ffffb171 == '\0') {
    DAT_ffffb16e = 0;
  }
  else if (DAT_ffffb172 == '\0') {
    DAT_ffffb16e = 1;
  }
  else if (DAT_ffffb173 == '\0') {
    DAT_ffffb16e = 2;
  }
  else {
    DAT_ffffb16e = 3;
  }
  return &DAT_ffffb173;
}



/* ROM address: 0x00043b68; body bytes: 96; decompiled */

void FUN_00043b68(void)

{
  if (DAT_ffffcab6 == '\0') {
    DAT_ffffcaaf = '\0';
    DAT_ffffcab4 = 0;
  }
  else if (DAT_ffffcaaf < 100) {
    DAT_ffffcaaf = DAT_ffffcaaf + 1;
    if (((DAT_ffffb5b8 <= 700.0) || (6500.0 <= DAT_ffffb5b8)) || (DAT_ffffaa10 <= 20.0)) {
      DAT_ffffcab4 = 0;
    }
    else {
      DAT_ffffcab4 = 1;
    }
  }
  else {
    DAT_ffffcaaf = 'd';
    DAT_ffffcab4 = 0;
  }
  return;
}



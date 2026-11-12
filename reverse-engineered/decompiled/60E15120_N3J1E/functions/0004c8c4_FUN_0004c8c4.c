/* ROM address: 0x0004c8c4; body bytes: 188; decompiled */

void FUN_0004c8c4(void)

{
  DAT_ffffcf42 = DAT_ffffbfbb == '\x01';
  DAT_ffffcf43 = DAT_ffffbfbc == '\x01';
  if ((((DAT_ffffcf67 == '\0') && (DAT_ffffbfb9 == '\x01')) ||
      ((DAT_ffffcf69 == '\0' && (DAT_ffffbfba == '\x01')))) ||
     ((((DAT_ffffcf70 == '\x01' || (DAT_ffffbfbb != '\x01')) || (cruise_enable_flag_ffffcf34 == '\0')) ||
      (DAT_ffffcf4f == '\x01')))) {
    DAT_ffffcf41 = 0;
  }
  else if ((DAT_ffffcf71 == '\0') && (DAT_ffffcf45 == '\x01')) {
    DAT_ffffcf41 = 1;
  }
  DAT_ffffcf70 = 0;
  DAT_ffffcf71 = DAT_ffffcf45;
  DAT_ffffcf67 = DAT_ffffbfb9;
  DAT_ffffcf69 = DAT_ffffbfba;
  return;
}



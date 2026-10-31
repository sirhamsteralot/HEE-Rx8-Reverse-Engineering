/* ROM address: 0x00026f38; body bytes: 102; decompiled */

void FUN_00026f38(void)

{
  if (660.0 <= engine_speed_rpm_ffffb548) {
    DAT_ffffb6be = '\0';
  }
  if ((engine_stopped_latch_ffffa41c == '\0') && (DAT_ffffb6be == '\x01')) {
    DAT_ffffb6a4 = 4;
    DAT_ffffb6a6 = 0xf;
  }
  else if (DAT_ffffb6ac == '\0') {
    DAT_ffffb6a4 = 0xff;
    DAT_ffffb6a6 = 0xf;
  }
  else if (DAT_ffffb6a4 != 0) {
    DAT_ffffb6a4 = DAT_ffffb6a4 + -1;
  }
  return;
}



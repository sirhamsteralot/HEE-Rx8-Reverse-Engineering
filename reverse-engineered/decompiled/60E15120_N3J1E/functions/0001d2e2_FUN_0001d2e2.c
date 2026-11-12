/* ROM address: 0x0001d2e2; body bytes: 188; decompiled */

void FUN_0001d2e2(void)

{
  if ((DAT_ffffb016 == 0) || (o2_monitor_enable_ffffae21 == '\0')) {
    DAT_ffffae1a = 0;
    DAT_ffffae1c = 0;
    DAT_ffffaff8 = 0.0;
  }
  else if (((DAT_ffffb06d == '\0') || (DAT_ffffb062 == 0)) || (DAT_ffffb016 < DAT_ffffae1c)) {
    DAT_ffffae1c = DAT_ffffb016;
  }
  else if (DAT_ffffb016 < DAT_ffffae1a) {
    DAT_ffffae1a = DAT_ffffb016;
  }
  else if (DAT_ffffae1c == 0) {
    if (DAT_ffffae1a != 0) {
      DAT_ffffae1a = DAT_ffffae1a - 1;
      if (DAT_ffffae1a == 0) {
        DAT_ffffae1c = DAT_ffffb016;
        DAT_ffffaff8 = 0.0 - DAT_ffffaff4;
      }
      else {
        DAT_ffffaff8 = DAT_ffffaff4;
      }
    }
  }
  else {
    DAT_ffffae1c = DAT_ffffae1c - 1;
    DAT_ffffaff8 = 0.0 - DAT_ffffaff4;
    if (DAT_ffffae1c == 0) {
      DAT_ffffae1a = DAT_ffffb016;
      DAT_ffffaff8 = DAT_ffffaff4;
    }
  }
  DAT_ffffb06d = o2_monitor_enable_ffffae21;
  DAT_ffffb062 = DAT_ffffb016;
  return;
}



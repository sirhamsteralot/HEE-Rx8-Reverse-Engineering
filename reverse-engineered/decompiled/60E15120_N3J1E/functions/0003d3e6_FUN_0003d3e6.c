/* ROM address: 0x0003d3e6; body bytes: 168; decompiled */

char FUN_0003d3e6(void)

{
  char cVar1;
  
  if ((((DAT_ffffb53a != '\0') && (at_drive_range_engaged_ffffb53c != '\x01')) || (engine_load_ffffc0b4 <= 0.3984)) ||
     (((engine_speed_rpm_ffffb548 < 2500.0 || (cVar1 = ref_getFaultStatus__(0x3a), cVar1 != '\0')) ||
      (DAT_ffffc590 != '\0')))) {
    DAT_ffffc61d = '\0';
  }
  else {
    DAT_ffffc61d = '\x01';
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc61e = 0;
    DAT_ffffc61f = 0;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffc61d;
    if (DAT_ffffc61d == '\x01') {
      if (vehicle_speed_ffffbbb4 < 3.76) {
        if (DAT_ffffc61c == '\0') {
          DAT_ffffc61e = 1;
          DAT_ffffc61f = 0;
        }
      }
      else {
        DAT_ffffc61f = 1;
        DAT_ffffc61e = 0;
      }
    }
  }
  return cVar1;
}



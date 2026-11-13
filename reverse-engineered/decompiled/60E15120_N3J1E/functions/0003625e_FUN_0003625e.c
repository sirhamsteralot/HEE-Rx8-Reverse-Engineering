/* ROM address: 0x0003625e; body bytes: 228; decompiled */

void FUN_0003625e(void)

{
  char cVar1;
  
  if (engine_running_flag_ffffaa68 == '\x01') {
    if (engine_speed_rpm_ffffb548 < 500.0) {
      cVar1 = FUN_000567aa(0x271);
    }
    else {
      cVar1 = '\0';
    }
    DAT_ffffc23a = cVar1 == '\x01';
    FUN_000363d0();
    FUN_0003641e();
    if ((((inferred_ram_c1d2_ffffc1d2_ffffc1d2 == '3') || ((DAT_ffffc275 & 2) != 0)) || (DAT_ffffc23a == '\x01')) &&
       ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
      FUN_00036464();
      FUN_00036540();
    }
    else {
      FUN_0003636c();
    }
  }
  else if ((DAT_ffffc246 == '\x01') && ((DAT_ffffc275 & 2) == 0)) {
    FUN_0003636c();
  }
  else {
    DAT_ffffc238 = 0;
    DAT_ffffc247 = 0;
    DAT_ffffc234 = 0;
    DAT_ffffc23c = 0;
  }
  DAT_ffffc246 = engine_running_flag_ffffaa68;
  return;
}



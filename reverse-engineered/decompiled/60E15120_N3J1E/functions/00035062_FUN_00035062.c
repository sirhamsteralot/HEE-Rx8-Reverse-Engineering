/* ROM address: 0x00035062; body bytes: 256; decompiled */

uint FUN_00035062(void)

{
  bool bVar1;
  uint uVar2;
  
  if (engine_speed_rpm_ffffb548 <= 500.0) {
    if ((engine_speed_rpm_ffffb548 <= 0.0) && (bVar1 = DAT_ffffc222 == 0, DAT_ffffc222 = 1, bVar1)) {
      DAT_ffffc212 = 15000;
    }
  }
  else {
    DAT_ffffc222 = 0;
  }
  if (DAT_ffffc21e == '\0') {
    if (DAT_ffffc248 == '\0') {
      inferred_ram_c274_ffffc274_ffffc274 = 1;
      DAT_ffffc22b = 1;
      inferred_ram_c1d3_ffffc1d3_ffffc1d3 = inferred_ram_c1d3_ffffc1d3_ffffc1d3 | 0x40;
      DAT_ffffc255 = 1;
    }
    DAT_ffffc226 = 1;
  }
  else if (DAT_ffffc21e == '\x01') {
    DAT_ffffc214 = 500;
    DAT_ffffc224 = 0x7f;
    FUN_00035738(0x81);
  }
  else {
    DAT_ffffc21e = '\x05';
    if (10.0 < inferred_battery_voltage_ffffb590) {
      if (DAT_ffffc214 != 0) {
        DAT_ffffc214 = DAT_ffffc214 + -1;
      }
      if (DAT_ffffc214 == 0) {
        DAT_ffffc226 = 1;
      }
    }
  }
  uVar2 = (uint)DAT_ffffc222;
  if (uVar2 == 1) {
    if (DAT_ffffc212 != 0) {
      DAT_ffffc212 = DAT_ffffc212 + -1;
    }
    uVar2 = (uint)DAT_ffffc222;
    if ((uVar2 == 1) && (DAT_ffffc212 == 0)) {
      uVar2 = FUN_00035738(200);
      DAT_ffffc21d = 5;
      DAT_ffffc21c = 1;
      DAT_ffffc212 = 500;
    }
  }
  return uVar2;
}



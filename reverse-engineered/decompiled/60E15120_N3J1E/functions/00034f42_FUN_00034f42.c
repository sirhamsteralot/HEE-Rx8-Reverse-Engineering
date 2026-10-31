/* ROM address: 0x00034f42; body bytes: 230; decompiled */

undefined4 * FUN_00034f42(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffc21e == '\x02') {
    if (DAT_ffffc204 == DAT_ffffc200) {
      ref_ImmoGoodStateSet_();
      DAT_ffffc224 = 0x7f;
      puVar1 = (undefined4 *)FUN_00035738(0x81);
      return puVar1;
    }
    ref_ImmoBadStateSet_();
    DAT_ffffc224 = 0x81;
    puVar1 = (undefined4 *)FUN_00035738(1);
    DAT_ffffc22a = 1;
  }
  else {
    if (DAT_ffffc21e == '\x01') {
      DAT_ffffc20c = 500;
      puVar1 = (undefined4 *)FUN_00034e68();
      return puVar1;
    }
    DAT_ffffc21e = '\x05';
    if (500.0 < engine_speed_rpm_ffffb548) {
      DAT_ffffc228 = '\x01';
    }
    if ((DAT_ffffc228 == '\x01') && (DAT_ffffc210 != 0)) {
      DAT_ffffc210 = DAT_ffffc210 + -1;
    }
    if (DAT_ffffc210 == 0) {
      ref_setImmoLight__(0);
      DAT_ffffc1d0 = 0;
    }
    puVar1 = &DAT_000350e8;
    if (10.0 < inferred_battery_voltage_ffffb590) {
      if (DAT_ffffc216 != 0) {
        DAT_ffffc216 = DAT_ffffc216 + -1;
      }
      puVar1 = &DAT_000350e8;
      if (DAT_ffffc216 == 0) {
        ref_ImmoBadStateSet_();
        DAT_ffffc224 = 0x80;
        puVar1 = (undefined4 *)FUN_00035738(1);
        DAT_ffffc22a = 1;
      }
    }
  }
  return puVar1;
}



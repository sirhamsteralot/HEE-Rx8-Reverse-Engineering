/* ROM address: 0x0003b3ea; body bytes: 300; decompiled */

char FUN_0003b3ea(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc596 = 0;
    DAT_ffffc597 = 0;
    DAT_ffffc598 = '\0';
    DAT_ffffc599 = '\0';
    DAT_ffffc58f = 'N';
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffd1ad == '\x01') || (DAT_ffffc590 == '\x01')) {
      DAT_ffffc58f = 'N';
    }
    else {
      bVar3 = false;
      if (engine_speed_rpm_ffffb548 < 2000.0) {
        if (65.0 < mass_air_flow_ffffa9ec) {
          if ((70.0 < inferred_coolant_temperature_ffffa98c) && (DAT_ffffc5e6 == '\0')) {
            bVar3 = true;
          }
        }
        else {
          DAT_ffffc598 = '\x01';
        }
      }
      bVar2 = false;
      if (((engine_running_ffffa428 == '\x01') && (50.0 < inferred_ram_ad48_ffffad48_ffffad48)) && (DAT_ffffcca1 == '\0')) {
        if (mass_air_flow_ffffa9ec < 9.0) {
          bVar2 = true;
        }
        else {
          DAT_ffffc599 = '\x01';
        }
      }
      if ((!bVar3) && (!bVar2)) {
        DAT_ffffc58f = 'N';
      }
    }
    if (DAT_ffffc58f == '\0') {
      cVar1 = ref_getFaultStatus__(9);
      if (cVar1 == '\0') {
        DAT_ffffc596 = 1;
        DAT_ffffc597 = 0;
        DAT_ffffc598 = '\0';
        DAT_ffffc599 = '\0';
      }
    }
    else {
      cVar1 = DAT_ffffc598;
      if ((DAT_ffffc598 == '\x01') && (cVar1 = DAT_ffffc599, DAT_ffffc599 == '\x01')) {
        cVar1 = ref_getFaultStatus__(9);
        if (cVar1 == '\0') {
          DAT_ffffc597 = 1;
          DAT_ffffc596 = 0;
        }
      }
    }
  }
  return cVar1;
}



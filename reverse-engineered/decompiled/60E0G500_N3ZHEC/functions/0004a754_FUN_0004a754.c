/* ROM address: 0x0004a754; body bytes: 216; decompiled */

void knock_sensor_health_persistence(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_ffffa325;
  if (DAT_ffffd201 == '\0') {
    cVar2 = FUN_000671a4(0x23);
    if ((cVar2 == '\0') && (cVar2 = FUN_000671a4(0x24), cVar2 == '\0')) {
      if (cVar1 != '\x02') {
        if (cVar1 != '\x01') {
          if (0x1e < DAT_ffffcda8) {
            DAT_ffffcda4 = 1;
            DAT_ffffcda6 = 1;
          }
          DAT_ffffcda8 = FUN_00002460((int)(short)DAT_ffffcda8,1);
          DAT_ffffcdaa = 0;
          DAT_ffffcdac = 0;
          return;
        }
        if (0x1e < DAT_ffffcdac) {
          DAT_ffffcda7 = 1;
        }
        DAT_ffffcdac = FUN_00002460((int)(short)DAT_ffffcdac,1);
        DAT_ffffcda8 = 0;
        DAT_ffffcdaa = 0;
        return;
      }
      if (0x1e < DAT_ffffcdaa) {
        DAT_ffffcda5 = 1;
      }
      DAT_ffffcdaa = FUN_00002460((int)(short)DAT_ffffcdaa,1);
    }
    else {
      DAT_ffffcdaa = 0;
    }
  }
  else {
    DAT_ffffcda5 = 0;
    DAT_ffffcda7 = 0;
    DAT_ffffcda4 = 0;
    DAT_ffffcda6 = 0;
    DAT_ffffcdaa = 0;
  }
  DAT_ffffcdac = 0;
  DAT_ffffcda8 = 0;
  return;
}



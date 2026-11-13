/* ROM address: 0x0002ae7c; body bytes: 298; decompiled */

uint FUN_0002ae7c(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = engine_running_ffffa428;
  if (vehicle_speed_ffffbbb4 <= 3.0) {
    if (vehicle_speed_ffffbbb4 <= 1.0) {
      DAT_ffffbb9f = '\0';
    }
  }
  else {
    DAT_ffffbb9f = '\x01';
  }
  uVar2 = (uint)engine_running_flag_ffffaa68;
  if (DAT_ffffbc0c == '\x01') {
    if (DAT_ffffc61e == '\0') {
      if ((uVar2 == 1) &&
         (((DAT_ffffbb9f == '\0' && (0x1e < DAT_ffffbb92)) ||
          ((DAT_ffffbb9f == '\x01' && (0x3a8 < DAT_ffffbb92)))))) {
        DAT_ffffbb71 = '\x01';
      }
    }
    else if (0x57d < DAT_ffffbb92) {
      DAT_ffffbb71 = '\x01';
    }
  }
  else {
    DAT_ffffbb71 = '\0';
  }
  if ((uVar2 == 1) &&
     (((engine_running_ffffa428 == '\0' && (DAT_ffffbb94 < 0x1f)) || (DAT_ffffbb71 == '\x01')))) {
    DAT_ffffbb67 = 1;
  }
  else {
    DAT_ffffbb67 = 0;
  }
  if (DAT_ffffbc0c == '\x01') {
    DAT_ffffbb92 = rx8_add_u16_saturate((int)(short)DAT_ffffbb92,1);
  }
  else {
    DAT_ffffbb92 = 0;
  }
  if ((uVar2 == 1) && (cVar1 == '\0')) {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffbb94,1);
    DAT_ffffbb94 = (ushort)uVar2;
  }
  else {
    DAT_ffffbb94 = 0;
  }
  return uVar2;
}



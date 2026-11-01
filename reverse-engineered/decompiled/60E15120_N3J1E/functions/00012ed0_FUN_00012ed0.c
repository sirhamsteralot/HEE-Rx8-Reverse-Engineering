/* ROM address: 0x00012ed0; body bytes: 308; decompiled */

uint FUN_00012ed0(void)

{
  bool bVar1;
  uint uVar2;
  
  if ((DAT_ffffa6dd == '\0') && (inferred_ram_a7ac_ffffa7ac_ffffa7ac - 150.0 <= engine_speed_rpm_ffffb548)) {
    DAT_ffffa6dd = '\x01';
  }
  if ((((secondary_air_pump_request_ffffbf6c == '\x01') && (engine_running_ffffa428 == '\x01')) && (DAT_ffffa6dd == '\x01')) &&
     (DAT_ffffce33 == '\0')) {
    DAT_ffffa6b6 = 1;
  }
  else {
    DAT_ffffa6b6 = 0;
  }
  if ((DAT_ffffa6de == '\x01') && (engine_running_ffffa428 == '\0')) {
    DAT_ffffa6dc = '\0';
  }
  else if ((DAT_ffffa6e0 == '\0') && (DAT_ffffa6b6 == 1)) {
    DAT_ffffa6dc = '\x01';
  }
  DAT_ffffa6de = engine_running_ffffa428;
  DAT_ffffa6e0 = DAT_ffffa6b6;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffa6b4 = 0;
  }
  else if (DAT_ffffa6dc == '\x01') {
    DAT_ffffa6b4 = rx8_add_u16_saturate((int)(short)DAT_ffffa6b4,1);
  }
  if ((DAT_ffffa6b6 == 0) || (0x75 < DAT_ffffa6b4)) {
    DAT_ffffa6b7 = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffa6b7 = 1;
    bVar1 = true;
  }
  if (DAT_ffffa6b6 == 0) {
    DAT_ffffa6b8 = 0;
  }
  else if (!bVar1) {
    DAT_ffffa6b8 = 1;
  }
  uVar2 = (uint)DAT_ffffa6b6;
  if ((uVar2 == 1) && ((cranking_active_ffffaa62_ffffaa62 == '\0' || (uVar2 = (uint)DAT_ffffb53a, uVar2 == 0)))) {
    DAT_ffffa6b9 = 1;
  }
  else {
    DAT_ffffa6b9 = 0;
  }
  return uVar2;
}



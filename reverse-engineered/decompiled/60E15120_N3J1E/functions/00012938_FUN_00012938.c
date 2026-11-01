/* ROM address: 0x00012938; body bytes: 136; decompiled */

char FUN_00012938(void)

{
  char cVar1;
  
  if (((((DAT_ffffb534 != '\x01') && (cVar1 = DAT_ffffca4c, DAT_ffffca4c != '\x01')) ||
       (cVar1 = cranking_active_ffffaa62_ffffaa62, cranking_active_ffffaa62_ffffaa62 != '\x01')) ||
      (((DAT_ffffa69f != '\x01' || (cVar1 = '\0', fuel_cut_flag_a_ffffa444 != '\0')) &&
       ((cVar1 = DAT_ffffa6a0, DAT_ffffa6a0 != '\x01' || (fuel_cut_flag_b_ffffa445 != '\0')))))) ||
     ((DAT_ffffa68c - engine_speed_rpm_ffffb548 < 40.0 || (2000.0 < engine_speed_rpm_ffffb548)))) {
    DAT_ffffa68a = 0;
  }
  else {
    DAT_ffffa68a = 1;
  }
  DAT_ffffa68c = engine_speed_rpm_ffffb548;
  DAT_ffffa69f = fuel_cut_flag_a_ffffa444;
  DAT_ffffa6a0 = fuel_cut_flag_b_ffffa445;
  return cVar1;
}



/* ROM address: 0x00021d8a; body bytes: 270; decompiled */

uint FUN_00021d8a(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = closed_loop_active_ffffae1f;
  if (closed_loop_active_ffffae1f == '\0') {
    if (DAT_ffffb32e == '\x01') {
      DAT_ffffb32d = 1;
    }
  }
  else {
    DAT_ffffb32d = 0;
  }
  if ((((DAT_ffffd040 == '\x01') || (DAT_ffffd0a8 == '\x01')) ||
      ((4500.0 <= engine_speed_rpm_ffffb548 && (DAT_ffffbe00 < 10.0)))) ||
     ((4.0 < vehicle_speed_ffffbbb4 && (DAT_ffffaa62 == '\x01')))) {
    DAT_ffffb2f6 = 0;
  }
  else if (((DAT_ffffb318 != '\x01') || (closed_loop_active_ffffae1f != '\x01')) ||
          ((DAT_ffffb0d6 != 0 && (intake_air_temperature_ffffaddc < 60.0)))) {
    DAT_ffffb2f6 = 0;
  }
  else {
    DAT_ffffb2f6 = 1;
  }
  uVar2 = (uint)DAT_ffffb32d;
  if (uVar2 == 1) {
    uVar2 = rx8_add_u16_saturate((int)DAT_ffffb328,1);
    DAT_ffffb328 = (short)uVar2;
  }
  else {
    DAT_ffffb328 = 0;
  }
  DAT_ffffb32e = cVar1;
  return uVar2;
}



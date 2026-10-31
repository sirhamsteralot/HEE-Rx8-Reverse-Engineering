/* ROM address: 0x000513d0; body bytes: 70; decompiled */

void FUN_000513d0(void)

{
  if (vehicle_speed_ffffbbb4 < 70.0) {
    if (vehicle_speed_ffffbbb4 < 66.24) {
      DAT_ffffd0f8 = 0;
    }
  }
  else {
    DAT_ffffd0f8 = 1;
  }
  if (vehicle_speed_ffffbbb4 < 130.0) {
    if (vehicle_speed_ffffbbb4 < 126.24) {
      DAT_ffffd0f9 = 0;
    }
  }
  else {
    DAT_ffffd0f9 = 1;
  }
  return;
}



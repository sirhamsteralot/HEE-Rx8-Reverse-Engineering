/* ROM address: 0x00025b36; body bytes: 110; decompiled */

uint FUN_00025b36(void)

{
  uint uVar1;
  
  if (vehicle_speed_ffffbbb4 < 20.0) {
    if (vehicle_speed_ffffbbb4 < 16.0) {
      DAT_ffffb649 = 1;
    }
  }
  else {
    DAT_ffffb649 = 0;
  }
  uVar1 = (uint)DAT_ffffaa62;
  if ((((uVar1 != 1) || (uVar1 = (uint)DAT_ffffb649, uVar1 != 1)) || (DAT_ffffb658 < 10.0)) ||
     (uVar1 = (uint)DAT_ffffb60c, uVar1 != 0)) {
    DAT_ffffb614 = 0;
  }
  else {
    DAT_ffffb614 = 1;
  }
  return uVar1;
}



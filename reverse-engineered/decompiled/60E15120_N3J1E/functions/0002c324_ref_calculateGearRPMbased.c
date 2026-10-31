/* ROM address: 0x0002c324; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002cadc (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_calculateGearRPMbased(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffb534;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffb53a, uVar1 == 0)) {
    if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 110.741) {
      if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 71.887) {
        if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 52.001) {
          if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 40.158) {
            if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 33.841) {
              if (engine_speed_rpm_ffffb548 < vehicle_speed_ffffbbb4 * 0.0) {
                DAT_ffffbc3c = 0;
                return 0;
              }
              uVar1 = 6;
            }
            else {
              uVar1 = 5;
            }
          }
          else {
            uVar1 = 4;
          }
        }
        else {
          uVar1 = 3;
        }
      }
      else {
        uVar1 = 2;
      }
      DAT_ffffbc3c = (undefined1)uVar1;
    }
    else {
      DAT_ffffbc3c = 1;
    }
  }
  else {
    DAT_ffffbc3c = 0;
  }
  return uVar1;
}



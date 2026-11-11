/* [ADDITIONAL SOURCE REVIEW]
 * candidate_gear_from_ratio [high]: Candidate gear 0xffffbc3c from rpm 0xffffb548 < vss 0xffffbbb4 * {110.741, 71.887, 52.001, 40.158, 33.841} -> gears 1-6, 0 when 0xffffb534!=1 or 0xffffb53a==1 (neutral); write pool 0x2c3d8. Emulator: vss=80, rpm=5752 -> bc3c=2. Called from 0x19aa0 (jsr 0x19ad6, pool 0x19c84). Export keeps inherited ref_calculateGearRPMbased.
 * RAM 0xffffbc3c candidate_gear (uint8): Candidate gear from rpm/vss ratio thresholds vss*110.741/71.887/52.001/40.158/33.841 rpm per km/h -> gears 1-6 (0 when 0xffffb534!=1 or neutral 0xffffb53a==1); pool 0x2c3d8. Emulator: vss=80 km/h, rpm=5752 -> 2.
 */
/* ROM address: 0x0002c324; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002cadc (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_calculateGearRPMbased(void)

{
  uint uVar1;
  
  uVar1 = (uint)automatic_transmission_ffffb534;
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



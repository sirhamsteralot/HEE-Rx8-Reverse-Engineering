/* [ADDITIONAL SOURCE REVIEW]
 * cruise_set_speed_latch [high]: Cruise set-speed state machine: latches set speed IN KM/H into learned readValue cell 0xffff866c (write site 0x32624, pool 0x32662), clamp [0, 200] (100 when 0xffffbd49==1) and floor 27.0 km/h; writes cruise target 0xffffbfa4 clamp [27, 100/200]. Emulator: vss 80 -> 866c=80.0, 250 -> 200.0, 10 -> 27.0. Called from batch 0x2e5c6 (jsr 0x2e620, pool 0x2e77c).
 * RAM 0xffff866c cruise_set_speed_kmh (float): Learned readValue cell with the cruise SET SPEED IN KM/H, written by 0x32614 (site 0x32624, pool 0x32662) clamped [27,200] (100 when 0xffffbd49==1); read by 0x32104/0x3290c/0x329fc/0x2e3dc/0x4ca7e (3.2 km/h tolerance vs 0xffffbfa0) and 0x2d83c. Emulator: vss 80 -> 80.0, 250 -> 200.0, 10 -> 27.0 km/h.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00032614; body bytes: 600; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003264a) */

void cruise_set_speed_latch(void)

{
  float arg1;
  float fVar1;
  float fVar2;
  float fVar3;
  float arg1_00;
  float snapshot_cruise_target_speed_kmh_ffffbfa4;
  
  arg1_00 = 0.0;
  fVar3 = DAT_ffffbfa0;
  snapshot_cruise_target_speed_kmh_ffffbfa4 = cruise_target_speed_kmh_ffffbfa4;
  arg1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&cruise_set_speed_kmh_ffff866c);
  if (DAT_ffffbfb4 == '\x01') {
    fVar1 = rx8_max_float(fVar3,27.0);
    fVar2 = fVar1;
  }
  else {
    fVar1 = arg1;
    fVar2 = arg1;
    if ((((fVar3 < arg1) || (DAT_ffffbfb5 != '\x01')) &&
        ((DAT_ffffbcec != '\0' || ((DAT_ffffbfd2 != '\x01' || (DAT_ffffbfb5 != '\0')))))) &&
       ((((DAT_ffffbfba != '\0' || (DAT_ffffbfb9 != '\0')) ||
         (((fVar3 - arg1 < 0.0 || (1.6 < fVar3 - arg1)) &&
          ((arg1 - fVar3 < 0.0 || (0.5 < arg1 - fVar3)))))) ||
        ((DAT_ffffbfd2 != '\x01' || (DAT_ffffbfb5 != '\0')))))) {
      if ((arg1 <= fVar3) || (DAT_ffffbfb5 != '\x01')) {
        fVar1 = arg1_00;
        fVar2 = snapshot_cruise_target_speed_kmh_ffffbfa4;
        if (((DAT_ffffbce9 != '\x01') && (fVar1 = arg1, fVar2 = 27.0, DAT_ffffbced != '\0')) &&
           (DAT_ffffbfc4 != '\x01')) {
          if (DAT_ffffbfb6 == '\x01') {
            fVar1 = rx8_max_float(arg1 - 1.6,27.0);
            fVar2 = fVar1;
          }
          else if (DAT_ffffbfb8 == '\x01') {
            fVar1 = arg1 + 1.6;
            fVar2 = arg1 + 1.6;
          }
          else if (DAT_ffffbfba == '\x01') {
            if ((DAT_ffffbfd0 == '\0') || ((DAT_ffffbfd2 == '\x01' && (DAT_ffffbfb5 == '\0')))) {
              fVar3 = 16.0;
            }
            else {
              fVar3 = 0.1;
            }
            fVar2 = snapshot_cruise_target_speed_kmh_ffffbfa4 - fVar3;
          }
          else {
            fVar2 = snapshot_cruise_target_speed_kmh_ffffbfa4;
            if (DAT_ffffbfb9 == '\x01') {
              if ((DAT_ffffbfd1 == '\0') || ((DAT_ffffbfd2 == '\x01' && (DAT_ffffbfb5 == '\0')))) {
                fVar3 = 1.0;
              }
              else {
                fVar3 = 0.025;
              }
              fVar2 = fVar3 + snapshot_cruise_target_speed_kmh_ffffbfa4;
            }
          }
        }
      }
      else {
        if (DAT_ffffbfd2 == '\0') {
          fVar3 = fVar3 + 0.0;
        }
        else {
          fVar3 = snapshot_cruise_target_speed_kmh_ffffbfa4 + 0.025;
        }
        fVar2 = rx8_min_float(fVar3,arg1);
        fVar1 = arg1;
      }
    }
  }
  if (DAT_ffffbd49 == '\x01') {
    DAT_ffffbfac = 100.0;
  }
  else {
    DAT_ffffbfac = 200.0;
  }
  fVar3 = rx8_clamp_float(fVar1,arg1_00,DAT_ffffbfac);
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar3,&cruise_set_speed_kmh_ffff866c);
  cruise_target_speed_kmh_ffffbfa4 = rx8_clamp_float(fVar2,27.0,DAT_ffffbfac);
  DAT_ffffbfa8 = cruise_target_speed_kmh_ffffbfa4;
  DAT_ffffbfc4 = '\0';
  DAT_ffffbfd2 = DAT_ffffbfb5;
  DAT_ffffbfd0 = DAT_ffffbfba;
  DAT_ffffbfd1 = DAT_ffffbfb9;
  return;
}



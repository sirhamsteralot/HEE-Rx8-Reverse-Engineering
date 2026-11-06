/* [ADDITIONAL SOURCE REVIEW]
 * fan_high_speed_decision [high]: High-speed (fan 2) command 0xffffbda2: coolant 98/101 C -> 0xffffbdac; load 0xffffc6ac 1.84/1.94 -> 0xffffbdb2; coolant 77/80 C -> 0xffffbdb3; vspeed 8/10 km/h -> 0xffffbdb4; bda2 = 1 when bda1==1 && counter 0xffffbda8 > 0x5c && (bdac || (bd68 && A/C switch bdb8) || (engine stopped && bda0 && !ccc6 && !a8ea && !bf8d) || bd6a || (bdb2==0 && bdb3 && !bdb4)) || 0xffffc5e6 || (d264 && !d269), gated by d263; bda8 counts up while bda1 (saturating u16).
 * RAM 0xffffbda8 fan_low_speed_timer (uint16): Saturating counter (rx8_add_u16_saturate) incremented while 0xffffbda1==1, cleared otherwise (0x2f65c); high-speed fan 2 requires bda8 > 0x5c (92 counts).
 */
/* ROM address: 0x0002f65c; body bytes: 406; decompiled */

uint fan_high_speed_decision(void)

{
  uint uVar1;
  
  if (inferred_coolant_temperature_ffffa98c < 101.0) {
    if (inferred_coolant_temperature_ffffa98c < 98.0) {
      DAT_ffffbdac = '\0';
    }
  }
  else {
    DAT_ffffbdac = '\x01';
  }
  if (inferred_ram_c6ac_ffffc6ac_ffffc6ac < 1.94) {
    if (inferred_ram_c6ac_ffffc6ac_ffffc6ac < 1.84) {
      DAT_ffffbdb2 = '\0';
    }
  }
  else {
    DAT_ffffbdb2 = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 80.0) {
    if (inferred_coolant_temperature_ffffa98c < 77.0) {
      DAT_ffffbdb3 = '\0';
    }
  }
  else {
    DAT_ffffbdb3 = '\x01';
  }
  if (vehicle_speed_ffffbbb4 < 10.0) {
    if (vehicle_speed_ffffbbb4 < 8.0) {
      DAT_ffffbdb4 = '\0';
    }
  }
  else {
    DAT_ffffbdb4 = '\x01';
  }
  uVar1 = (uint)fan_low_speed_cmd_ffffbda1;
  if (((((uVar1 == 1) && (0x5c < fan_low_speed_timer_ffffbda8)) &&
       ((((DAT_ffffbdac == '\x01' ||
          (((DAT_ffffbdac == '\0' && (DAT_ffffbd68 == '\x01')) && (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\x01')))) ||
         ((((DAT_ffffaa68 == '\0' && (DAT_ffffbda0 == '\x01')) && (DAT_ffffccc6 == '\0')) &&
          ((DAT_ffffa8ea == '\0' && (apv_target_state_ffffbf8d == '\0')))))) ||
        ((DAT_ffffbd6a == '\x01' ||
         (((DAT_ffffbdb2 == '\0' && (DAT_ffffbdb3 == '\x01')) && (DAT_ffffbdb4 == '\0')))))))) ||
      ((DAT_ffffc5e6 == '\x01' || ((DAT_ffffd264 == '\x01' && (DAT_ffffd269 == '\0')))))) &&
     (DAT_ffffd263 == '\0')) {
    fan_high_speed_cmd_ffffbda2 = 1;
  }
  else {
    fan_high_speed_cmd_ffffbda2 = 0;
  }
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)fan_low_speed_timer_ffffbda8,1);
    fan_low_speed_timer_ffffbda8 = (ushort)uVar1;
  }
  else {
    fan_low_speed_timer_ffffbda8 = 0;
  }
  return uVar1;
}



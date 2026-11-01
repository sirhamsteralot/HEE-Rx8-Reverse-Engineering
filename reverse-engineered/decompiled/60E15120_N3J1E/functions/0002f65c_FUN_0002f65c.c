/* ROM address: 0x0002f65c; body bytes: 406; decompiled */

uint FUN_0002f65c(void)

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
  uVar1 = (uint)DAT_ffffbda1;
  if (((((uVar1 == 1) && (0x5c < DAT_ffffbda8)) &&
       ((((DAT_ffffbdac == '\x01' ||
          (((DAT_ffffbdac == '\0' && (DAT_ffffbd68 == '\x01')) && (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\x01')))) ||
         ((((DAT_ffffaa68 == '\0' && (DAT_ffffbda0 == '\x01')) && (DAT_ffffccc6 == '\0')) &&
          ((DAT_ffffa8ea == '\0' && (apv_target_state_ffffbf8d == '\0')))))) ||
        ((DAT_ffffbd6a == '\x01' ||
         (((DAT_ffffbdb2 == '\0' && (DAT_ffffbdb3 == '\x01')) && (DAT_ffffbdb4 == '\0')))))))) ||
      ((DAT_ffffc5e6 == '\x01' || ((DAT_ffffd264 == '\x01' && (DAT_ffffd269 == '\0')))))) &&
     (DAT_ffffd263 == '\0')) {
    DAT_ffffbda2 = 1;
  }
  else {
    DAT_ffffbda2 = 0;
  }
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbda8,1);
    DAT_ffffbda8 = (ushort)uVar1;
  }
  else {
    DAT_ffffbda8 = 0;
  }
  return uVar1;
}



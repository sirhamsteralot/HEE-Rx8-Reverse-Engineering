/* ROM address: 0x0002f51a; body bytes: 248; decompiled */

char FUN_0002f51a(void)

{
  char cVar1;
  
  if (inferred_coolant_temperature_ffffa98c < 97.0) {
    if (inferred_coolant_temperature_ffffa98c < 94.0) {
      DAT_ffffbdaa = '\0';
    }
  }
  else {
    DAT_ffffbdaa = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 97.0) {
    if (inferred_coolant_temperature_ffffa98c < 94.0) {
      DAT_ffffbdab = '\0';
    }
  }
  else {
    DAT_ffffbdab = '\x01';
  }
  if (((((((DAT_ffffbdaa == '\x01') || ((DAT_ffffbdab == '\x01' && (DAT_ffffb0cd == '\x01')))) ||
         ((DAT_ffffaa68 == '\0' &&
          ((((DAT_ffffbda0 == '\x01' && (DAT_ffffccc6 == '\0')) && (DAT_ffffa8ea == '\0')) &&
           (apv_target_state_ffffbf8d == '\0')))))) || ((DAT_ffffbd68 == '\x01' || (DAT_ffffbd6a == '\x01')))) &&
       ((DAT_ffffd040 == '\0' && (cVar1 = '\0', DAT_ffffd0a8 == '\0')))) ||
      ((cVar1 = '\x01', DAT_ffffd264 == '\x01' || (cVar1 = DAT_ffffd269, DAT_ffffd269 == '\x01'))))
     && (DAT_ffffd263 == '\0')) {
    DAT_ffffbda1 = 1;
  }
  else {
    DAT_ffffbda1 = 0;
  }
  return cVar1;
}



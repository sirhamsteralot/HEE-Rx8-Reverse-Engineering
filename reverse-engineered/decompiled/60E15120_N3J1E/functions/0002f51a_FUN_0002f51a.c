/* [ADDITIONAL SOURCE REVIEW]
 * fan_low_speed_decision [high]: Low-speed (fan 1) command 0xffffbda1: coolant hysteresis 94/97 C -> 0xffffbdaa/0xffffbdab; bda1 = 1 when (bdaa || (bdab && 0xffffb0cd)) || (engine stopped 0xffffaa68==0 && 0xffffbda0 && !0xffffccc6 && !0xffffa8ea && !0xffffbf8d) || (0xffffbd68 || 0xffffbd6a), gated by fault flags 0xffffd040/0xffffd0a8/0xffffd264/0xffffd269/0xffffd263. Reads bda1 via pool 0x2f63a at 0x2f58a.
 */
/* ROM address: 0x0002f51a; body bytes: 248; decompiled */

char fan_low_speed_decision(void)

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
    fan_low_speed_cmd_ffffbda1 = 1;
  }
  else {
    fan_low_speed_cmd_ffffbda1 = 0;
  }
  return cVar1;
}



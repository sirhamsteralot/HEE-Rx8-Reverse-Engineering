/* ROM address: 0x0004f840; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d45c (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0004f840(void)

{
  char cVar1;
  
  if ((((((DAT_ffffd160 < 5.0) || (40.0 <= DAT_ffffd160)) || (DAT_ffffd00f != '\x01')) ||
       ((inferred_battery_voltage_ffffb590 <= 20.0 || (14.60938 <= inferred_battery_voltage_ffffb590)))) ||
      ((DAT_ffffcf94 != '\x01' || ((DAT_ffffcf95 != '\0' || (DAT_ffffce18 != '\x01')))))) ||
     ((DAT_ffffd242 != '\0' ||
      ((DAT_ffffd008 < -11.0 ||
       (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e2,0), cVar1 != '\0')))))) {
    DAT_ffffd00e = 0;
  }
  else {
    DAT_ffffd00e = 1;
  }
  return 0;
}



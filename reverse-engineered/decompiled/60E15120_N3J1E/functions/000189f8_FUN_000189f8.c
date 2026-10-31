/* ROM address: 0x000189f8; body bytes: 176; decompiled */

undefined1 * FUN_000189f8(void)

{
  undefined1 *puVar1;
  
  if (vehicle_speed_ffffbbb4 < 3.0) {
    if (vehicle_speed_ffffbbb4 < 1.0) {
      DAT_ffffa97e = '\0';
    }
  }
  else {
    DAT_ffffa97e = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 60.0) {
    if (inferred_coolant_temperature_ffffa98c < 57.0) {
      DAT_ffffa97f = '\0';
    }
  }
  else {
    DAT_ffffa97f = '\x01';
  }
  puVar1 = (undefined1 *)(uint)DAT_ffffb53a;
  if (((puVar1 == (undefined1 *)0x1) ||
      ((DAT_ffffb534 == '\0' && (puVar1 = &DAT_ffffcc91, 2 < DAT_ffffcc91)))) &&
     ((DAT_ffffa97e == '\0' &&
      (((DAT_ffffa401 == '\0' || (puVar1 = &DAT_ffffa402, DAT_ffffa402 == '\0')) &&
       ((puVar1 = (undefined1 *)0x1, DAT_ffffa97f == '\x01' ||
        (puVar1 = (undefined1 *)(uint)DAT_ffffc5e6, puVar1 == (undefined1 *)0x1)))))))) {
    DAT_ffffa96b = 1;
  }
  else {
    DAT_ffffa96b = 0;
  }
  return puVar1;
}



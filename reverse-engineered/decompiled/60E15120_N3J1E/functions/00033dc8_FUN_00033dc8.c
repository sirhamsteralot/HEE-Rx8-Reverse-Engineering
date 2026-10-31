/* ROM address: 0x00033dc8; body bytes: 110; decompiled */

undefined2 * FUN_00033dc8(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  
  puVar1 = &engine_on_time_counter_ffffa426;
  DAT_ffffc0cc = DAT_ffffc0e0 * DAT_ffffc0ec + DAT_ffffc0d0 * DAT_ffffc0dc +
                 DAT_ffffc0f0 * DAT_ffffc0fc;
  if ((engine_on_time_counter_ffffa426 == 0) ||
     ((DAT_ffffc108 == '\x01' && (puVar1 = (undefined2 *)0x1, engine_speed_rpm_ffffb548 < 812.5)))) {
    DAT_ffffc0c8 = 0.0;
  }
  else {
    DAT_ffffc0c8 = rx8_min_float(DAT_ffffc0cc * DAT_ffffc100,16.0);
    puVar1 = extraout_r0;
  }
  return puVar1;
}



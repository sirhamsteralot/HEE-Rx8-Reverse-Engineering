/* ROM address: 0x0000eefa; body bytes: 372; decompiled */

undefined1 * FUN_0000eefa(void)

{
  undefined1 *puVar1;
  
  if (engine_speed_rpm_ffffb548 < 5500.0) {
    if (engine_speed_rpm_ffffb548 < 5300.0) {
      DAT_ffffa4ab = 0;
    }
  }
  else {
    DAT_ffffa4ab = 1;
  }
  if (engine_speed_rpm_ffffb548 < 9000.0) {
    if (engine_speed_rpm_ffffb548 < 8800.0) {
      DAT_ffffa4ac = 0;
    }
  }
  else {
    DAT_ffffa4ac = 1;
  }
  if ((((coolant_below_18c_flag_ffffa4a6 == '\x01') || (rev_limit_countdown_active_ffffa4aa == 1)) &&
      (puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1), DAT_ffffa4ab == 0)) ||
     (((coolant_below_18c_flag_ffffa4a6 == '\0' && (puVar1 = &rev_limit_countdown_active_ffffa4aa, rev_limit_countdown_active_ffffa4aa == 0)) && (DAT_ffffa4ac == 0))
     )) {
    rev_limit_state_b_ffffa4a5 = 0;
    rev_limit_state_a_ffffa4a4 = 0;
    rev_limit_state_c_ffffa4a8 = 0;
  }
  else {
    if ((((coolant_below_18c_flag_ffffa4a6 == '\x01') || (rev_limit_countdown_active_ffffa4aa == 1)) && (DAT_ffffa4ab == 1)) ||
       (((coolant_below_18c_flag_ffffa4a6 == '\0' && (rev_limit_countdown_active_ffffa4aa == 0)) && (DAT_ffffa4ac == 1)))) {
      rev_limit_state_a_ffffa4a4 = 1;
      rev_limit_state_c_ffffa4a8 = rx8_add_u16_saturate((int)rev_limit_state_c_ffffa4a8,1);
    }
    if (DAT_ffffb53a == '\0') {
      if ((((coolant_below_18c_flag_ffffa4a6 == '\x01') && (DAT_ffffa4ab == 1)) &&
          (puVar1 = (undefined1 *)(int)rev_limit_state_c_ffffa4a8, (undefined1 *)0x113 < puVar1)) ||
         (((puVar1 = (undefined1 *)(uint)rev_limit_countdown_active_ffffa4aa,
           puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1) &&
           (puVar1 = (undefined1 *)(uint)DAT_ffffa4ab,
           puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) ||
          ((coolant_below_18c_flag_ffffa4a6 == '\0' &&
           (((rev_limit_countdown_active_ffffa4aa == 0 &&
             (puVar1 = (undefined1 *)(uint)DAT_ffffa4ac,
             puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) &&
            (puVar1 = (undefined1 *)(int)rev_limit_state_c_ffffa4a8, (undefined1 *)0x1c2 < puVar1)))))))) {
        rev_limit_state_b_ffffa4a5 = 1;
      }
    }
    else {
      puVar1 = (undefined1 *)(uint)rev_limit_state_a_ffffa4a4;
      if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
        rev_limit_state_b_ffffa4a5 = 1;
      }
    }
  }
  return puVar1;
}



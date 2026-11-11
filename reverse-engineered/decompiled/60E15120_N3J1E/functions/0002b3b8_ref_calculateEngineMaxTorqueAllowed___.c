/* [ADDITIONAL SOURCE REVIEW]
 * engine_max_torque_allowed_calc [high]: 0xffffbbd8 = clamp((0xffffbb20 * decode_u8_affine(0x3ec99326, 0, 0xffffbbc8)/100.0 - 0xffffbcb8) - 0xffffbcbc, 0, 512.0); 512.0 (failsafe) when engine running and validity/fault flags clear, else decode of the 0x212 torque byte. Read by 0x17f20 and 0x1815c dsc_timing_derate_select (pool 0x1827c at 0x18188). Called from 0x2a2ae via pool 0x2a46c.
 */
/* ROM address: 0x0002b3b8; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bb0c (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void engine_max_torque_allowed_calc(void)

{
  float fVar1;
  float arg1;
  
  arg1 = 0.0;
  if ((((DAT_ffffbb24 == '\0') && (DAT_ffffbb28 == '\0')) && (engine_running_ffffa428 == '\x01')) &&
     (((DAT_ffffbbe8 != 0 && (DAT_ffffa401 == '\0')) && (can_error_latch_ffffa40a == '\0')))) {
    fVar1 = (float)rx8_decode_u8_affine(0x3ec99326,0,(int)can212_torque_signal_ffffbbc8);
  }
  else {
    fVar1 = 512.0;
  }
  engine_max_torque_allowed_ffffbbd8 = rx8_clamp_float(((DAT_ffffbb20 * fVar1) / 100.0 - DAT_ffffbcb8) - DAT_ffffbcbc,arg1
                                 ,512.0);
  return;
}



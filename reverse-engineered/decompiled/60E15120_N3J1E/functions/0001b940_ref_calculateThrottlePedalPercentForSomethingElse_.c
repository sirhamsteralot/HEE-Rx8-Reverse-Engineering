/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffad44 inferred_throttle_position (float): Plate position 0-84 (deg-ish): ad44 = ad38/ad3c (from AN18/AN19 via 0x1b08e/0x1b14c -> a218/a21c -> ad30/ad34, learned zeros 0xffff807c/0xffff8084) in 0x1b940; limp value 20.0 when cc99==1; ad48 = ad44/84.0f (0x42a80000)*100. Read by PID 0x093c handler 0x56e04, tbl 0x6a180 lookups 0x21a80/0x21ae8, fault 0x33e98.
 * RAM 0xffffcc98 plate_tp2_source_select (uint8): Read by 0x1b940: ==1 selects the TP2 branch (ad44 = ad3c instead of ad38); also referenced by 0x1b166/0x1b3f2/0x1b6fc/0x1ba20/0x470d0/0x47704/0x487d6 (engine_stop_conditions_eval).
 * RAM 0xffffcc99 limp_home_request (uint8): Read by 0x1b940: together with cc98==1 forces ad44 = 20.0 (limp plate position); also referenced by 0x1b166/0x1b3f2/0x1b6fc/0x1ba20/0x487d6.
 */
/* ROM address: 0x0001b940; body bytes: 224; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001c3f0 (224 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateThrottlePedalPercentForSomethingElse_(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  fVar1 = DAT_ffffad30 - fVar1;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&learned_plate_zero_2_ffff8084);
  arg0 = 0.0;
  fVar2 = DAT_ffffad34 - fVar2;
  DAT_ffffad38 = rx8_max_float(0.0,fVar1);
  DAT_ffffad3c = rx8_max_float(arg0,fVar2);
  if (plate_tp2_source_select_ffffcc98 == '\x01') {
    inferred_throttle_position_ffffad44 = DAT_ffffad3c;
    if (limp_home_request_ffffcc99 == '\x01') {
      inferred_throttle_position_ffffad44 = 20.0;
    }
  }
  else {
    inferred_throttle_position_ffffad44 = DAT_ffffad38;
  }
  DAT_ffffad40 = rx8_max_float(arg0,inferred_throttle_position_ffffad44 - idle_air_required_ffffb2a4);
  fVar1 = (float)rx8_divide_with_zero_fallback(inferred_throttle_position_ffffad44,0x42a80000);
  inferred_ram_ad48_ffffad48_ffffad48 = fVar1 * 100.0;
  DAT_ffffad4c = DAT_ffffad40 - DAT_ffffadac;
  DAT_ffffadac = DAT_ffffada8;
  DAT_ffffada8 = DAT_ffffad40;
  DAT_ffffad50 = inferred_throttle_position_ffffad44 - DAT_ffffad94;
  DAT_ffffad94 = DAT_ffffad90;
  DAT_ffffad90 = inferred_throttle_position_ffffad44;
  return;
}



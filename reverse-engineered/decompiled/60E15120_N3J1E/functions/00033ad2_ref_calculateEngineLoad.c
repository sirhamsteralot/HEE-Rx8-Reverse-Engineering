/* [ADDITIONAL SOURCE REVIEW]
 * calculate_engine_load [high]: engine_load c0b4 = min(first_order_filter(c0b0, c0b4, 0.2 or 1.0 by c0c4), c0b8); forced 0.525 when a41c or (c0c5==0 && injectors off a42c); c0c5 = previous a42c. PID 0x0043 'Engine Load' encodes c0b4 (handler 0x56b8a).
 * RAM 0xffffc0b0 engine_load_raw (float): c0b0 = raw load input filtered into engine_load c0b4 (coeff 0.2, or 1.0 when c0c4 set).
 * RAM 0xffffc0b8 engine_load_max (float): c0b8 = clamp maximum for engine_load c0b4 = min(filter(c0b0,...), c0b8).
 * RAM 0xffffc0c4 load_filter_fast_flag (uint8): c0c4 selects filter coefficient 1.0 vs 0.2 in calculate_engine_load.
 * RAM 0xffffc0c5 injectors_off_previous (uint8): c0c5 = previous engine_injectors_off a42c; forces load 0.525 on injector-off edge.
 */
/* ROM address: 0x00033ad2; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003424a (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 calculate_engine_load(void)

{
  char cVar1;
  undefined4 extraout_r0;
  undefined4 uVar2;
  float arg0;
  
  cVar1 = engine_injectors_off_ffffa42c;
  if ((engine_stopped_latch_ffffa41c == '\x01') || ((injectors_off_previous_ffffc0c5 == '\0' && (engine_injectors_off_ffffa42c == '\x01')))) {
    uVar2 = 1;
    engine_load_ffffc0b4 = 0.525;
  }
  else {
    if (load_filter_fast_flag_ffffc0c4 == '\0') {
      arg0 = rx8_first_order_filter(engine_load_raw_ffffc0b0,engine_load_ffffc0b4,0.2,1e-05);
    }
    else {
      arg0 = rx8_first_order_filter(engine_load_raw_ffffc0b0,engine_load_ffffc0b4,1.0,1e-05);
    }
    engine_load_ffffc0b4 = rx8_min_float(arg0,engine_load_max_ffffc0b8);
    uVar2 = extraout_r0;
  }
  injectors_off_previous_ffffc0c5 = cVar1;
  return uVar2;
}



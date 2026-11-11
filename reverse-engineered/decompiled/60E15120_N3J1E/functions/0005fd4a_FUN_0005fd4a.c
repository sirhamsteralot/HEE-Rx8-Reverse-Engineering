/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_eval_enable [high]: Entry 0x5fd4a: extu.b r4; r5 = pool 0x5fe10 = 0xffffd688 (dtc_eval_enable RAM); r4==1 -> mov.b #1,@r5; r4==0 -> mov.b #0,@r5; rts (000b at 0x5fd68). Plain setter of the global DTC eval-enable flag, not a thunk. Callers: 0x5fd6c (boot DTC RAM init sets 1) and 0x5dde8 (UDS 0x85 control-DTC-setting path, handler 0x5dc44).
 * RAM 0xffffd688 dtc_eval_enable (uint8): 1 = fault evaluation active; set at init by 0x5fd6c via 0x5fd4a(1); selects path in 0x5fe20.
 */
/* ROM address: 0x0005fd4a; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e656 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

char dtc_set_eval_enable(char param_1)

{
  if (param_1 == '\x01') {
    dtc_eval_enable_ffffd688 = 1;
  }
  else if (param_1 == '\0') {
    dtc_eval_enable_ffffd688 = 0;
  }
  return param_1;
}



/* [ADDITIONAL SOURCE REVIEW]
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



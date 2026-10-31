/* [ADDITIONAL SOURCE REVIEW]
 * fuel_cut_arbitration [medium]: Sets fuel-cut flags a444/a445 from requests a464/a465 and param_1 mode (band checks 0/6 vs 12/18, mirrors a4a2/a4a3); calls FUN_0000e2d4.
 * RAM 0xffffa444 fuel_cut_flag_a (uint8): Set by fuel_cut_arbitration (0xedc4) from request a464 / mode param.
 * RAM 0xffffa445 fuel_cut_flag_b (uint8): Second fuel-cut flag set alongside a444 in 0xedc4.
 * RAM 0xffffa464 fuel_cut_request_a (uint8): Input request: when set, a444 = a445 = 1 unconditionally.
 * RAM 0xffffa465 fuel_cut_request_b (uint8): Input request: with a4a3/a4a2 mirrors gates a444 by param_1 band (0/12 vs 6/18).
 * RAM 0xffffa4a2 fuel_cut_request_a_prev (uint8): Mirror of a464 stored at end of 0xedc4.
 * RAM 0xffffa4a3 fuel_cut_request_b_prev (uint8): Mirror of a465 stored at end of 0xedc4.
 */
/* ROM address: 0x0000edc4; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000edc8 (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_fuel_cut_arbitration(char param_1)

{
  if (fuel_cut_request_a_ffffa464 == '\x01') {
    fuel_cut_flag_a_ffffa444 = 1;
    fuel_cut_flag_b_ffffa445 = 1;
    goto LAB_0000ee36;
  }
  if (fuel_cut_request_b_ffffa465 == '\x01') {
    if (fuel_cut_request_b_prev_ffffa4a3 == '\0') {
      if ((param_1 != '\x06') && (param_1 != '\x12')) {
        fuel_cut_flag_a_ffffa444 = 0;
        fuel_cut_flag_b_ffffa445 = 1;
        goto LAB_0000ee36;
      }
    }
    else {
      if (fuel_cut_request_a_prev_ffffa4a2 != '\x01') goto LAB_0000ee36;
      if ((param_1 != '\0') && (param_1 != '\f')) {
        fuel_cut_flag_a_ffffa444 = 0;
        fuel_cut_flag_b_ffffa445 = 1;
        goto LAB_0000ee36;
      }
    }
    fuel_cut_flag_a_ffffa444 = 1;
  }
  else {
    fuel_cut_flag_a_ffffa444 = 0;
  }
  fuel_cut_flag_b_ffffa445 = 0;
LAB_0000ee36:
  fuel_cut_request_a_prev_ffffa4a2 = fuel_cut_request_a_ffffa464;
  fuel_cut_request_b_prev_ffffa4a3 = fuel_cut_request_b_ffffa465;
  FUN_0000e2d4();
  return;
}



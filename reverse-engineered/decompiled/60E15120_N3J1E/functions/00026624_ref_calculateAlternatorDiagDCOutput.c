/* [ADDITIONAL SOURCE REVIEW]
 * alternator_duty_calc [medium]: Field duty: 0xffffb5f0 = 3.75 (pool 0x26734) when alt-speed flag b613 set and 0xffffb5e0 within band of b5a0, else 3-D lookup 0x6a5c4(alt speed, b5e0); filtered (factor 0.1244 pool 0x74a40) into 0xffffb5f4; 0xffffb5f8 = clamp((b5f4 - prev*0.9672)/0x3d065950, 0, 3.75); 0xffffb620 = clamp(tbl 0x6a560(b5f8), 0, 100) when b5e0 out of band and b612==0; 0xffffb5ac = ref_diagAlternatorSignalthing(0x5c800)(b620). Called from 0x267c6 via pool 0x268a4.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a5c4: Alternator Voltage Delta - Diagnostic Request (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00026624; body bytes: 238; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00026f48 (238 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_alternator_duty_calc(void)

{
  char cVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float arg3;
  undefined4 snapshot_DAT_ffffb5e0;
  float arg1;
  
  arg3 = 1e-05;
  fVar4 = DAT_ffffb5f4;
  snapshot_DAT_ffffb5e0 = electrical_load_raw_ffffb5e0;
  cVar1 = rx8_is_outside_tolerance_band(electrical_load_raw_ffffb5e0,alternator_target_field_ffffb5a0,0x3727c5ac);
  arg1 = 0.0;
  cVar2 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffb5e0,0,arg3);
  fVar3 = arg1;
  if (DAT_ffffb613 != '\0') {
    if (cVar1 == '\0') {
      DAT_ffffb5f0 = 3.75;
      fVar3 = DAT_ffffb5f0;
    }
    else {
      fVar3 = (float)lookup_3d_descriptor_scaled(inferred_alternator_speed_ffffb598,snapshot_DAT_ffffb5e0,&LAB_0006a5c4);
    }
  }
  DAT_ffffb5f0 = fVar3;
  DAT_ffffb5f4 = rx8_first_order_filter(DAT_ffffb5f0,DAT_ffffb5f4,0.1244,arg3);
  fVar4 = (float)rx8_divide_with_zero_fallback(DAT_ffffb5f4 - fVar4 * 0.9672,0x3d065950);
  DAT_ffffb5f8 = rx8_clamp_float(fVar4,arg1,3.75);
  if ((cVar2 != '\0') && (DAT_ffffb612 != '\x01')) {
    fVar4 = (float)lookup_2d_descriptor_scaled(DAT_ffffb5f8,&DAT_0006a560);
    arg1 = rx8_clamp_float(fVar4,arg1,100.0);
  }
  DAT_ffffb620 = arg1;
  inferred_ram_b5ac_ffffb5ac_ffffb5ac = candidate_alternator_duty_encode_u16(DAT_ffffb620);
  return;
}



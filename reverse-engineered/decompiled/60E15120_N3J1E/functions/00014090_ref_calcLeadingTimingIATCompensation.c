/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a0d8: Ignition Leading/Trailing - Intake Air Temperature Compensation - On Throttle (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * iat_timing_compensation_on_throttle [high]: was ref_calcLeadingTimingIATCompensation. a778 = a77c = lookup_2d(IAT, tbl 0x6a0d8 'Ignition Leading/Trailing - IAT Compensation - On Throttle') when load>=0.5; 0 when load<0.5; cranking uses tbl 0x6a0ec ('Table 2D - 113'). Consumed as -a778/-a77c in the blend.
 * RAM 0xffffa778 iat_timing_compensation_leading (float): Written by 0x14090 iat_timing_compensation_on_throttle (fmov.s fr5/fr0,@r14 0x140b8/0x140d2/0x140d4 via mov.w pool 0x140e2=0xa778 @0x14098); read by 0x123da (pool 0x1253e @0x124bc).
 * RAM 0xffffa77c iat_timing_compensation_trailing (float): Written by 0x14090 iat_timing_compensation_on_throttle (fmov.s fr3,@r3 0x140da via mov.w pool 0x140ea=0xa77c @0x140d8); read by 0x124d6 (pool 0x1268c @0x125a0).
 */
/* ROM address: 0x00014090; body bytes: 82; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000140b6) */
/* Unique exact-byte match to related 60E0FC00 function at 00013ff4 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint iat_timing_compensation_on_throttle(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  
  if (cranking_active_ffffaa62_ffffaa62 == 1) {
    puVar2 = &tbl_table_2d_113_0006a0ec;
  }
  else {
    if (engine_load_ffffc0b4 < 0.5) {
      iat_timing_compensation_leading_ffffa778 = 0;
      iat_timing_compensation_trailing_ffffa77c = 0;
      return (uint)cranking_active_ffffaa62_ffffaa62;
    }
    puVar2 = &tbl_ignition_leading_trailing_intake_air_temperature_compensation_on_throttle_0006a0d8;
  }
  uVar1 = lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,puVar2);
  iat_timing_compensation_leading_ffffa778 = extraout_fr0;
  iat_timing_compensation_trailing_ffffa77c = extraout_fr0;
  return uVar1;
}



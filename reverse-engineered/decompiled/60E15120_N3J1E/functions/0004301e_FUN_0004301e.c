/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004301e; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042852 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004301e(void)

{
  char cVar1;
  float arg1;
  float snapshot_engine_speed_rpm_ffffb548;
  float snapshot_DAT_ffffca24;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  snapshot_DAT_ffffca24 = DAT_ffffca24;
  DAT_ffffca10 = rx8_clamp_float(DAT_ffffb558,1.0,150.0);
  arg1 = 0.0;
  cVar1 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffca24,0,0x3727c5ac);
  if (cVar1 != '\0') {
    DAT_ffffca0c = 1000.0 / (snapshot_DAT_ffffca24 * 4.0);
  }
  DAT_ffffca08 = DAT_ffffca0c / DAT_ffffca10 - 3.0;
  DAT_ffffca04 = (snapshot_engine_speed_rpm_ffffb548 - DAT_ffffca50) / DAT_ffffca10;
  DAT_ffffca00 = rx8_max_float(DAT_ffffca04,arg1);
  DAT_ffffca50 = snapshot_engine_speed_rpm_ffffb548;
  return;
}



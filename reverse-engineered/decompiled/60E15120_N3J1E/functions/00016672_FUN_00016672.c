/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00016672; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00016476 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00016672(void)

{
  char cVar1;
  char cVar2;
  float snapshot_DAT_ffffa8a4;
  
  snapshot_DAT_ffffa8a4 = DAT_ffffa8a4;
  cVar1 = rx8_is_outside_tolerance_band(DAT_ffffa8a4,0,0x3727c5ac);
  cVar2 = DAT_ffffa8bc;
  if ((((DAT_ffffa8bc != '\x01') || (DAT_ffffa7ac <= engine_speed_rpm_ffffb548)) ||
      ((DAT_ffffa8bd != '\x01' && (cVar2 = DAT_ffffa8be, DAT_ffffa8be != '\x01')))) ||
     (((cVar2 = engine_running_ffffa428, engine_running_ffffa428 != '\x01' || (0.01 <= snapshot_DAT_ffffa8a4)) || (cVar1 == '\0')))) {
    DAT_ffffa8a8 = 0;
  }
  else {
    DAT_ffffa8a8 = 1;
  }
  return cVar2;
}



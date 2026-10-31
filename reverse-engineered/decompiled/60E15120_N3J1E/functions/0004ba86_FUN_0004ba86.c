/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004ba86; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004ac3e (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004ba86(void)

{
  byte snapshot_DAT_ffffce49;
  uint uVar2;
  
  snapshot_DAT_ffffce49 = DAT_ffffce49;
  uVar2 = (uint)DAT_ffffce50;
  if ((uVar2 == 1) && (uVar2 = (uint)DAT_ffffce49, uVar2 == 0)) {
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(intake_air_temperature_ffffaddc,&DAT_ffff8774);
  }
  DAT_ffffce50 = snapshot_DAT_ffffce49;
  return uVar2;
}



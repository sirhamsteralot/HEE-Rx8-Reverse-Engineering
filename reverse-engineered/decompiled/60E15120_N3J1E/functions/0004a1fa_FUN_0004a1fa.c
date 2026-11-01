/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004a1fa; body bytes: 306; decompiled */

undefined1 * FUN_0004a1fa(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar5;
  undefined1 *puVar4;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar3 = DAT_ffffd1c5;
  cVar2 = DAT_ffffcd83;
  cVar1 = cranking_active_ffffaa62_ffffaa62;
  if ((DAT_ffffd1c5 == '\x01') || ((DAT_ffffcd83 == '\0' && (DAT_ffffcdb4 == '\x01')))) {
    DAT_ffffcd86 = 10;
  }
  else if (DAT_ffffcd86 != 0) {
    DAT_ffffcd86 = DAT_ffffcd86 + -1;
  }
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if ((cranking_active_ffffaa62_ffffaa62 == '\0') && (DAT_ffffd1c5 == '\0')) {
    if (DAT_ffffcdb5 == '\x01') {
      DAT_ffffcdb6 = '\x01';
    }
    if (DAT_ffffcdb6 == '\x01') {
      DAT_ffffcda8 = rx8_add_u16_saturate((int)(short)DAT_ffffcda8,1);
    }
  }
  else {
    DAT_ffffcdb6 = '\0';
    DAT_ffffcda8 = 0;
  }
  cVar5 = ref_getFaultStatus__(0x59);
  if (((((((cVar5 != '\0') || (cVar5 = ref_getFaultStatus__(0x5a), cVar5 != '\0')) ||
         (DAT_ffffb108 != '\x01')) || ((snapshot_inferred_coolant_temperature_ffffa98c < 70.0 || (120.0 <= snapshot_inferred_coolant_temperature_ffffa98c)))) ||
       ((110.0 <= intake_air_temperature_ffffaddc || ((DAT_ffffae20 != '\0' || (DAT_ffffcda8 < 0x7e)))))) ||
      (DAT_ffffcdb6 != '\x01')) || ((DAT_ffffcd86 != 0 || (cVar3 != '\0')))) {
    puVar4 = &DAT_ffffcd9c;
    DAT_ffffcd9c = 0;
  }
  else {
    DAT_ffffcd9c = 1;
    puVar4 = (undefined1 *)0x0;
  }
  DAT_ffffcdb4 = cVar2;
  DAT_ffffcdb5 = cVar1;
  return puVar4;
}



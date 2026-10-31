/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00015ffc; body bytes: 302; decompiled */

uint FUN_00015ffc(void)

{
  byte snapshot_DAT_ffffa7b4;
  char cVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  float snapshot_DAT_ffffa838;
  
  cVar2 = DAT_ffffa7b5;
  snapshot_DAT_ffffa7b4 = DAT_ffffa7b4;
  fVar5 = rx8_absolute_difference(DAT_ffffa7ac,DAT_ffffb550);
  snapshot_DAT_ffffa838 = DAT_ffffa838;
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffa8cc,0,0x3727c5ac);
  uVar4 = (uint)snapshot_DAT_ffffa7b4;
  if (((((uVar4 != 1) || (DAT_ffffa892 < 0x138)) || (cVar2 != '\0')) ||
      ((((DAT_ffffa894 < 0x138 || (inferred_coolant_temperature_ffffa98c < 80.0)) ||
        ((60.0 <= intake_air_temperature_ffffaddc || ((37.0 < fVar5 || (cVar3 != '\0')))))) || (0.035 < DAT_ffffa7a4)))
      ) || ((((35.0 < DAT_ffffb2f0 || (snapshot_DAT_ffffa838 <= DAT_ffffa840)) || (DAT_ffffa83c <= snapshot_DAT_ffffa838)) ||
            ((DAT_ffffa7b7 != '\0' || (DAT_ffffcc91 != '\0')))))) {
    DAT_ffffa890 = 0;
  }
  else {
    DAT_ffffa890 = 1;
  }
  if (uVar4 == 1) {
    uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffa892,1);
    DAT_ffffa892 = (ushort)uVar4;
  }
  else {
    DAT_ffffa892 = 0;
  }
  if (cVar2 == '\0') {
    uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffa894,1);
    DAT_ffffa894 = (ushort)uVar4;
  }
  else {
    DAT_ffffa894 = 0;
  }
  return uVar4;
}



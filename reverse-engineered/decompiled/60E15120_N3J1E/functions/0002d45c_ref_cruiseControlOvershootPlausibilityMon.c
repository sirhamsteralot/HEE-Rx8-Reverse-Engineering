/* ROM address: 0x0002d45c; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002db00 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_cruiseControlOvershootPlausibilityMon(void)

{
  char cVar1;
  undefined4 *puVar2;
  float fVar3;
  
  cVar1 = DAT_ffffbfba;
  fVar3 = DAT_ffffbfa0 - cruise_target_speed_kmh_ffffbfa4;
  puVar2 = (undefined4 *)(uint)DAT_ffffbced;
  if ((puVar2 != (undefined4 *)((int)&vector_Poweron_Reset + 1)) ||
     (((((DAT_ffffbcf7 != '\0' || (DAT_ffffbfba != '\0')) || (DAT_ffffbfb5 != 0)) ||
       (puVar2 = &DAT_00076780, fVar3 < 10.0)) &&
      (((puVar2 = (undefined4 *)(uint)DAT_ffffbfb5,
        puVar2 != (undefined4 *)((int)&vector_Poweron_Reset + 1) || (fVar3 < 10.0)) ||
       (puVar2 = (undefined4 *)0x1d4c, DAT_ffffbcf4 < 0x1d4c)))))) {
    DAT_ffffbceb = 0;
  }
  else {
    DAT_ffffbceb = 1;
  }
  if (fVar3 < 10.0) {
    DAT_ffffbcf4 = 0;
  }
  else {
    puVar2 = (undefined4 *)rx8_add_u16_saturate((int)(short)DAT_ffffbcf4,1);
    DAT_ffffbcf4 = (ushort)puVar2;
  }
  DAT_ffffbcf7 = cVar1;
  return puVar2;
}



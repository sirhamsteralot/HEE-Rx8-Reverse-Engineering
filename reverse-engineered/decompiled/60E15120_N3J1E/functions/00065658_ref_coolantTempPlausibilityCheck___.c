/* ROM address: 0x00065658; body bytes: 56; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00063f48 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_coolantTempPlausibilityCheck___(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0005fc78();
  fVar3 = (float)FUN_0005fc7e();
  puVar1 = &DAT_00065754;
  if ((71.0 <= fVar2) && (puVar1 = &DAT_00065758, 22.0 <= fVar2 - fVar3)) {
    puVar1 = (undefined4 *)rx8_pack_u8_with_complement(1);
    _DAT_ffff8e7e = SUB42(puVar1,0);
  }
  return puVar1;
}



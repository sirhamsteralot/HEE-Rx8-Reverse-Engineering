/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00026d70; body bytes: 304; decompiled */

undefined4 * FUN_00026d70(void)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  float fVar4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar2 = DAT_ffffd1c5;
  cVar1 = DAT_ffffba60;
  fVar4 = 3000.0;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  if (((DAT_ffffb6c0 == '\0') && (DAT_ffffd1c5 == '\0')) && (DAT_ffffb6bf == DAT_ffffba60)) {
    DAT_ffffb6bc = rx8_add_u16_saturate((int)DAT_ffffb6bc,1);
  }
  else {
    DAT_ffffb6bc = 0;
  }
  puVar3 = (undefined4 *)(uint)DAT_ffffb6aa;
  if ((((puVar3 != (undefined4 *)((int)&vector_Poweron_Reset + 1)) || (fVar4 <= DAT_ffffb6a0)) ||
      ((puVar3 = (undefined4 *)(uint)DAT_ffffb6ab,
       puVar3 != (undefined4 *)((int)&vector_Poweron_Reset + 1) ||
       ((puVar3 = (undefined4 *)(int)DAT_ffffb0ca, puVar3 != (undefined4 *)0x0 ||
        (inferred_coolant_temperature_ffffa98c <= 0.0)))))) ||
     ((puVar3 = &DAT_ffffa92c, 0.0 < DAT_ffffa92c ||
      (((((snapshot_engine_speed_rpm_ffffb548 < 660.0 || (4500.0 <= snapshot_engine_speed_rpm_ffffb548)) ||
         (puVar3 = &engine_load_ffffc0b4, engine_load_ffffc0b4 < DAT_ffffb698)) ||
        ((engine_stopped_latch_ffffa41c != '\0' || (puVar3 = (undefined4 *)&DAT_ffffb6bc, DAT_ffffcf90 <= 0.0)))) ||
       (cVar2 != '\0')))))) {
    DAT_ffffb6ac = 0;
  }
  else {
    DAT_ffffb6ac = 1;
  }
  DAT_ffffb6bf = cVar1;
  DAT_ffffb6c0 = cVar2;
  return puVar3;
}



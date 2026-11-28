/* [ADDITIONAL SOURCE REVIEW]
 * misfire_enable_window [high]: DAT_ffffb6ac = 1 only when b6aa!=0 && DAT_ffffb6a0 >= 3000.0 (pool 0x75450) && b6ab!=0 && DAT_ffffb0ca==0 && coolant 0xffffa98c > 0.0 && DAT_ffffa92c > 0.0 && 660.0 <= rpm < 4500.0 && load 0xffffc0b4 >= b698 && engine_stopped_latch 0xffffa41c == 0 && DAT_ffffd1c5 == 0; else 0. Also bumps b6bc when b6c0==0 && d1c5==0 && b6bf==ba60. Pools verified: 0x26e08=0x75450 (3000.0), 0x26e14=0xffffb6c0, 0x26e18=0xffffb6bf. Called from 0x287aa.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00026d70; body bytes: 304; decompiled */

undefined4 * misfire_enable_window(void)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  float fVar4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar2 = DAT_ffffd1c5;
  cVar1 = misfire_high_rpm_active_ffffba60;
  fVar4 = 3000.0;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  if (((DAT_ffffb6c0 == '\0') && (DAT_ffffd1c5 == '\0')) && (DAT_ffffb6bf == misfire_high_rpm_active_ffffba60)) {
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



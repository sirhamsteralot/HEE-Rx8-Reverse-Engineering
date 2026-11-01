/* [ADDITIONAL SOURCE REVIEW]
 * can201_prepare_rpm_with_conditional_filter [high]: Reads confirmed RPM 0xffffb548, conditionally filters into 0xffffbb04 and stores previous input at 0xffffbb08. Exact conditions include unresolved status flags.
 * RAM 0xffffbb04 can201_prepared_engine_rpm (float): Conditional filtered RPM; input from 0xffffb548.
 * RAM 0xffffbb08 can201_previous_engine_rpm (float): Previous unfiltered input saved each call.
 */
/* ROM address: 0x00029340; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029ce8 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * can201_prepare_rpm_with_conditional_filter(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  float fVar2;
  float fVar3;
  float arg0;
  
  arg0 = engine_speed_rpm_ffffb548;
  fVar2 = rx8_absolute_difference(engine_speed_rpm_ffffb548,can201_previous_engine_rpm_ffffbb08);
  puVar1 = &DAT_000293fc;
  fVar3 = arg0;
  if ((((vehicle_speed_ffffbbb4 <= 0.099999994) &&
       (puVar1 = (undefined4 *)(uint)engine_running_ffffa428, puVar1 == (undefined4 *)0x1)) &&
      (puVar1 = (undefined4 *)(uint)cranking_active_ffffaa62_ffffaa62, puVar1 == (undefined4 *)0x1)) &&
     ((arg0 < inferred_ram_a7ac_ffffa7ac_ffffa7ac + 150.0 && (fVar2 < 30.0)))) {
    fVar3 = rx8_first_order_filter(arg0,can201_prepared_engine_rpm_ffffbb04,0.04,1e-05);
    puVar1 = extraout_r0;
  }
  can201_prepared_engine_rpm_ffffbb04 = fVar3;
  can201_previous_engine_rpm_ffffbb08 = arg0;
  return puVar1;
}



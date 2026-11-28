/* [ADDITIONAL SOURCE REVIEW]
 * misfire_learn_steady_state [high]: DAT_ffffba0a = 1 (learn allowed) only when b69c==1 && engine_running_timer 0xffffa424 >= 0x9c4 (2500) && injectors not off (0xffffa42c==0) && DAT_ffffba19 < 8 && |DAT_ffffad50| within tolerance band && engine_load_delta 0xffffc150 < 1.05 && DAT_ffffb0ca==0 && DAT_ffffba1a < 0x10 && coolant 0xffffa98c >= 70.0 && 660.0 <= rpm < 8500.0 && DAT_ffffaa81==0 && DAT_ffffba1c==0 && DAT_ffffba1b < 8 && DAT_ffffb2f0 > 0.0 (else 0.2 < DAT_ffffb220) && DAT_ffffb2f4 >= 0x271; on fail ba06 = 8, on pass ba06 decays. Pools: 0x2765c=0x2440, 0x27660=0x23dc, 0x27664=0xffffba0a, 0x27668=0xffffba06. Called from 0x287aa.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00027520; body bytes: 358; decompiled */

code * misfire_learn_steady_state(void)

{
  uint uVar1;
  code *pcVar2;
  float fVar3;
  float snapshot_engine_speed_rpm_ffffb548;
  float snapshot_inferred_ram_b2f0_ffffb2f0_ffffb2f0;
  
  fVar3 = 0.0;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  snapshot_inferred_ram_b2f0_ffffb2f0_ffffb2f0 = inferred_ram_b2f0_ffffb2f0_ffffb2f0;
  uVar1 = rx8_is_outside_tolerance_band(inferred_ram_b2f0_ffffb2f0_ffffb2f0,0,0x3727c5ac);
  fVar3 = rx8_absolute_difference(DAT_ffffad50,fVar3);
  pcVar2 = (code *)(uint)misfire_supply_enable_ffffb69c;
  if (((((((pcVar2 != (code *)((int)&vector_Poweron_Reset + 1)) ||
          (pcVar2 = (code *)0x9c4, engine_running_timer_ffffa424 < 0x9c4)) ||
         (pcVar2 = (code *)(int)engine_injectors_off_ffffa42c, pcVar2 != (code *)0x0)) ||
        ((pcVar2 = (code *)&DAT_ffffba19, DAT_ffffba19 < 8 || (0.97 <= fVar3)))) ||
       (((1.05 <= engine_load_delta_ffffc150 ||
         ((DAT_ffffb0ca != '\0' || (pcVar2 = (code *)&DAT_0007558e, DAT_ffffba1a < 0x10)))) ||
        (inferred_coolant_temperature_ffffa98c < 70.0)))) ||
      (((snapshot_engine_speed_rpm_ffffb548 < 660.0 || (8500.0 <= snapshot_engine_speed_rpm_ffffb548)) ||
       (pcVar2 = (code *)(uint)DAT_ffffaa81, pcVar2 != (code *)((int)&vector_Poweron_Reset + 1)))))
     || (((pcVar2 = (code *)(uint)DAT_ffffba1c, pcVar2 != (code *)(uVar1 & 0xff) ||
          (pcVar2 = (code *)&DAT_ffffba1b, DAT_ffffba1b < 8)) ||
         (((uVar1 & 0xff) != 0 &&
          (((snapshot_inferred_ram_b2f0_ffffb2f0_ffffb2f0 <= 0.0 || (0.2 < DAT_ffffb220)) ||
           (pcVar2 = (code *)&DAT_00075598, DAT_ffffb2f4 < 0x271)))))))) {
    DAT_ffffba0a = 0;
    DAT_ffffba06 = 8;
  }
  else {
    DAT_ffffba0a = 1;
    if (DAT_ffffba06 != 0) {
      DAT_ffffba06 = DAT_ffffba06 + -1;
    }
  }
  return pcVar2;
}



/* [ADDITIONAL SOURCE REVIEW]
 * charging_dtc_timer_a [medium]: 0xffffb608 = 0x138 when (b654 > 18.471 || b658 > 15.938 || engine stopped || b638 < 0x3f || b645==0 || (b645==1 && b63a < 0x3f)), else counts down; counters b638/b63a saturate while running/voltage >= 10 (b645 from battery volts 9/10 thresholds). Called from 0x2680e via pool 0x268b4.
 * RAM 0xffffb658 system_voltage_alt (float): Second voltage rail used in the charging DTC timers (thresholds 15.938/10.938 pools 0x7497c/0x7498c/0x74984) by 0x257b4/0x2590a; distinct from filtered battery volts 0xffffb590.
 */
/* ROM address: 0x000257b4; body bytes: 280; decompiled */

undefined2 * candidate_charging_dtc_timer_a(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  if (inferred_battery_voltage_ffffb590 < 10.0) {
    if (inferred_battery_voltage_ffffb590 < 9.0) {
      DAT_ffffb645 = '\0';
    }
  }
  else {
    DAT_ffffb645 = '\x01';
  }
  if ((18.471 < inferred_ram_b654_ffffb654_ffffb654) || (15.938 < system_voltage_alt_ffffb658)) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    puVar2 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  puVar1 = puVar2;
  if (((((puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) || (engine_running_ffffa428 == 0)) ||
       ((puVar1 = (undefined2 *)(uint)engine_running_ffffa428,
        puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1) &&
        (puVar1 = &DAT_00074962, DAT_ffffb638 < 0x3f)))) || (DAT_ffffb645 == '\0')) ||
     ((DAT_ffffb645 == '\x01' && (puVar1 = (undefined2 *)&UNK_0000003f, DAT_ffffb63a < 0x3f)))) {
    DAT_ffffb608 = 0x138;
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffb608;
    if (puVar1 != (undefined2 *)0x0) {
      DAT_ffffb608 = DAT_ffffb608 - 1;
    }
  }
  if (engine_running_ffffa428 == 0) {
    DAT_ffffb638 = 0;
  }
  else {
    puVar1 = (undefined2 *)rx8_add_u16_saturate((int)(short)DAT_ffffb638,1);
    DAT_ffffb638 = (ushort)puVar1;
  }
  if (DAT_ffffb645 == '\0') {
    DAT_ffffb63a = 0;
  }
  else {
    puVar1 = (undefined2 *)rx8_add_u16_saturate((int)(short)DAT_ffffb63a,1);
    DAT_ffffb63a = (ushort)puVar1;
  }
  if (DAT_ffffb608 == 0) {
    DAT_ffffb5b0 = 1;
    puVar2 = puVar1;
  }
  else if (puVar2 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffb5b0 = 0;
  }
  return puVar2;
}



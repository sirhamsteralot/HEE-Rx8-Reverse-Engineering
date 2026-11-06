/* [ADDITIONAL SOURCE REVIEW]
 * idle_drive_flags [medium]: Vehicle-speed thresholds 3/4 km/h -> 0xffffa827; 0xffffa9bc < 1.0/1.5 -> 0xffffa821; sets 0xffffa7b6 when a821==1 && a820>1; snapshots bd69/b53a/b534. Called from 0x167c0 via pool 0x168a4.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00014944; body bytes: 516; decompiled */

undefined2 * candidate_idle_drive_flags(void)

{
  char cVar1;
  byte snapshot_DAT_ffffb53a;
  char cVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar3 = ac_clutch_on_ffffbd69;
  snapshot_DAT_ffffb53a = DAT_ffffb53a;
  cVar1 = automatic_transmission_ffffb534;
  if (vehicle_speed_ffffbbb4 <= 4.0) {
    if (vehicle_speed_ffffbbb4 <= 3.0) {
      DAT_ffffa827 = '\0';
    }
  }
  else {
    DAT_ffffa827 = '\x01';
  }
  if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 1.5) {
    if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 1.0) {
      DAT_ffffa821 = '\0';
    }
  }
  else {
    DAT_ffffa821 = '\x01';
  }
  if ((DAT_ffffa821 == '\x01') && (1 < DAT_ffffa820)) {
    DAT_ffffa7b6 = '\x01';
  }
  else if ((DAT_ffffa821 == '\0') && (0x3d < DAT_ffffa80a)) {
    DAT_ffffa7b6 = '\0';
  }
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  if (DAT_ffffa821 == '\x01') {
    DAT_ffffa820 = rx8_add_u8_saturate((int)(char)DAT_ffffa820,1);
    DAT_ffffa80a = 0;
  }
  else {
    DAT_ffffa820 = 0;
    DAT_ffffa80a = rx8_add_u16_saturate((int)(short)DAT_ffffa80a,1);
  }
  uVar6 = 0x3727c5ac;
  if (((DAT_ffffa844 == '\0') || (cranking_active_ffffaa62_ffffaa62 == '\0')) || ((cVar1 == '\x01' && (snapshot_DAT_ffffb53a == 0)))) {
    DAT_ffffa7f0 = 0x3e;
    DAT_ffffa7ec = snapshot_engine_speed_rpm_ffffb548;
  }
  else {
    if (DAT_ffffa7f0 != 0) {
      DAT_ffffa7f0 = DAT_ffffa7f0 + -1;
    }
    DAT_ffffa7ec = rx8_first_order_filter(snapshot_engine_speed_rpm_ffffb548,DAT_ffffa7ec,0.08,1e-05);
  }
  if ((cVar3 == '\0') && (DAT_ffffa822 == '\x01')) {
    DAT_ffffa7b4 = 0;
    puVar5 = (undefined2 *)0x1;
  }
  else {
    puVar4 = (undefined2 *)rx8_is_outside_tolerance_band(DAT_ffffa8a4,0,uVar6);
    puVar5 = puVar4;
    if (((((DAT_ffffb578 != '\0') ||
          (((puVar5 = &engine_running_timer_ffffa424, engine_running_timer_ffffa424 < 0x7d || (DAT_ffffa827 != '\0')) ||
           (DAT_ffffa7b6 != '\0')))) ||
         ((cVar1 != '\0' && (puVar5 = (undefined2 *)(uint)snapshot_DAT_ffffb53a, puVar5 != (undefined2 *)0x1)))) ||
        (((((uint)puVar4 & 0xff) != 0 || ((150.0 < DAT_ffffa7ec - snapshot_engine_speed_rpm_ffffb548 || (DAT_ffffa7f0 != 0)))) &&
         (inferred_ram_a7ac_ffffa7ac_ffffa7ac < snapshot_engine_speed_rpm_ffffb548)))) ||
       ((((DAT_ffffc5e6 != '\0' ||
          (puVar5 = (undefined2 *)(int)DAT_ffffc5db, puVar5 != (undefined2 *)0x0)) ||
         (puVar5 = (undefined2 *)&DAT_ffffc590, DAT_ffffc590 != '\0')) || (DAT_ffffc61e != '\0'))))
    {
      DAT_ffffa7b4 = 0;
    }
    else {
      DAT_ffffa7b4 = 1;
    }
  }
  DAT_ffffa822 = cVar3;
  return puVar5;
}



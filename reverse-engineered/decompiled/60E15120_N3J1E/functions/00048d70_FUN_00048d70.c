/* [ADDITIONAL SOURCE REVIEW]
 * voltage_key_sanity_flags [medium]: Sets 0xffffccc5/0xffffccc2 = (voltage 0xffffb590 >= 6.0), 0xffffccc4 = (ccc2 && 0xffffccca == 0), 0xffffccc3 = (0xffffaa68 && 0xffffccc1 && stored 0xffffb4ed == 1); voltage/key sanity inputs to the shutdown decision.
 */
/* ROM address: 0x00048d70; body bytes: 166; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00048dea) */
/* WARNING: Removing unreachable block (ram,0x00048df6) */
/* WARNING: Removing unreachable block (ram,0x00048e0c) */

char candidate_voltage_key_sanity_flags(void)

{
  char cVar1;
  
  if (inferred_battery_voltage_ffffb590 < 6.0) {
    DAT_ffffccc2 = 0;
    DAT_ffffccc4 = 0;
  }
  else {
    DAT_ffffccc5 = 1;
    DAT_ffffccc2 = 1;
    if (key_voltage_timer_ffffccca == 0) {
      DAT_ffffccc4 = 1;
    }
    else {
      DAT_ffffccc4 = 0;
    }
  }
  cVar1 = engine_running_flag_ffffaa68 == '\x01';
  if (((engine_running_flag_ffffaa68 == '\x01') && (cVar1 = shutdown_allowed_ffffccc1, shutdown_allowed_ffffccc1 == '\x01')) &&
     (cVar1 = DAT_ffffb4ed, DAT_ffffb4ed == '\x01')) {
    DAT_ffffccc3 = 1;
  }
  else {
    DAT_ffffccc3 = 0;
  }
  return cVar1;
}



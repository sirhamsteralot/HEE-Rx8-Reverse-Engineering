/* [ADDITIONAL SOURCE REVIEW]
 * knock_enable_gate [high]: Sets DAT_ffffa73d: engine-running timer 0xffffa424 >= 0x177, coolant >= 10 C, load >= tbl 0x6af54 (0.5 flat, RPM axis 800-9600), RPM < 5000.
 * RAM 0xffffa424 engine_running_timer (uint16): Engine-running time counter (100 Hz); gates knock enable (>= 0x177) and the attack condition (>= 0xfa).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00013826; body bytes: 100; decompiled */

undefined2 * knock_enable_gate(void)

{
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffa740 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_knock_enable_load_floor_0006af54);
  if ((((engine_running_timer_ffffa424 < 0x177) || (inferred_coolant_temperature_ffffa98c < 10.0)) || (engine_load_ffffc0b4 < DAT_ffffa740)) ||
     (5000.0 <= snapshot_engine_speed_rpm_ffffb548)) {
    knock_enable_ffffa73d = 0;
  }
  else {
    knock_enable_ffffa73d = 1;
  }
  return &engine_running_timer_ffffa424;
}



/* [ADDITIONAL SOURCE REVIEW]
 * low_voltage_dtc_timer [medium]: 0xffffb60e = 0x138 unless (b654 >= 8.486699 (pool 0x74a1c) && b5e0 > 19.531 && engine running && counters full && volts >= 10); 0xffffb5b2 = 1 when b60e==0, else 0 when b654 >= 8.486699. Called from 0x2680e via pool 0x268c0.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002635c; body bytes: 264; decompiled */

void candidate_low_voltage_dtc_timer(void)

{
  float snapshot_inferred_ram_b654_ffffb654_ffffb654;
  
  if (inferred_battery_voltage_ffffb590 < 10.0) {
    if (inferred_battery_voltage_ffffb590 < 9.0) {
      DAT_ffffb647 = '\0';
    }
  }
  else {
    DAT_ffffb647 = '\x01';
  }
  if (((((8.486699 <= inferred_ram_b654_ffffb654_ffffb654) || (electrical_load_raw_ffffb5e0 <= 19.531)) || (engine_running_ffffa428 == '\0')) ||
      ((engine_running_ffffa428 == '\x01' && (DAT_ffffb640 < 0x3f)))) ||
     ((DAT_ffffb647 == '\0' || ((DAT_ffffb647 == '\x01' && (DAT_ffffb642 < 0x3f)))))) {
    DAT_ffffb60e = 0x138;
  }
  else if (DAT_ffffb60e != 0) {
    DAT_ffffb60e = DAT_ffffb60e + -1;
  }
  snapshot_inferred_ram_b654_ffffb654_ffffb654 = inferred_ram_b654_ffffb654_ffffb654;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffb640 = 0;
  }
  else {
    DAT_ffffb640 = rx8_add_u16_saturate((int)(short)DAT_ffffb640,1);
  }
  if (DAT_ffffb647 == '\0') {
    DAT_ffffb642 = 0;
  }
  else {
    DAT_ffffb642 = rx8_add_u16_saturate((int)(short)DAT_ffffb642,1);
  }
  if (DAT_ffffb60e == 0) {
    low_voltage_latch_ffffb5b2 = 1;
  }
  else if (8.486699 <= snapshot_inferred_ram_b654_ffffb654_ffffb654) {
    low_voltage_latch_ffffb5b2 = 0;
  }
  return;
}



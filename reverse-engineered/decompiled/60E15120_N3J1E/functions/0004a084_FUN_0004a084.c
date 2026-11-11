/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_dtc_report [high]: Raises DTC 0x23/0x24 via dtc_set_fault_x0 from cd65/cd67 (cd64/cd66 reported as status 2).
 * RAM 0xffffcd65 knock_sensor_fault_a (uint8): Channel A fault persistence -> DTC 0x23 via 0x4a084.
 * RAM 0xffffcd67 knock_sensor_fault_b (uint8): Channel B fault persistence -> DTC 0x24 via 0x4a084.
 */
/* ROM address: 0x0004a084; body bytes: 92; decompiled */

uint knock_sensor_dtc_report(void)

{
  uint uVar1;
  
  if (knock_sensor_fault_a_ffffcd65 == '\x01') {
    dtc_set_fault_x0(0x23,1);
  }
  else if (knock_sensor_healthy_a_ffffcd64 == '\x01') {
    dtc_set_fault_x0(0x23,2);
  }
  if (knock_sensor_fault_b_ffffcd67 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x24,1);
  }
  else {
    uVar1 = (uint)knock_sensor_healthy_b_ffffcd66;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x24,2);
    }
  }
  return uVar1;
}



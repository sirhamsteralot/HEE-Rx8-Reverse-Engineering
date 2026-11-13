/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_health_gate [high]: Sets knock_sensors_healthy_ffffa73e = (0xffffcd64 && 0xffffcd66); both set by 0x49fac after >30 healthy knock-sensor counts.
 * RAM 0xffffa73d knock_enable (uint8): Set by 0x13826: run timer >= 0x177, coolant >= 10 C, load >= 0.5, RPM < 5000.
 * RAM 0xffffa73e knock_sensors_healthy (uint8): Set by 0x1388a = cd64 && cd66 (0x49fac health persistence).
 * RAM 0xffffcd64 knock_sensor_healthy_a (uint8): Set by 0x49fac after >30 healthy counts (channel A); gates a73e.
 * RAM 0xffffcd66 knock_sensor_healthy_b (uint8): Channel B counterpart of cd64.
 */
/* ROM address: 0x0001388a; body bytes: 40; decompiled */

char knock_sensor_health_gate(void)

{
  char cVar1;
  
  cVar1 = knock_sensor_healthy_a_ffffcd64;
  if ((knock_sensor_healthy_a_ffffcd64 == '\x01') && (cVar1 = knock_sensor_healthy_b_ffffcd66, knock_sensor_healthy_b_ffffcd66 == '\x01')) {
    knock_sensors_healthy_ffffa73e = 1;
  }
  else {
    knock_sensors_healthy_ffffa73e = 0;
  }
  return cVar1;
}



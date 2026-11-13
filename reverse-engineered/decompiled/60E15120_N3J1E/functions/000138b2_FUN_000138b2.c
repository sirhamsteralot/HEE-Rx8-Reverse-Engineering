/* [ADDITIONAL SOURCE REVIEW]
 * knock_active_gate [high]: Sets knock_active_ffffa73c = knock_enable_ffffa73d && knock_sensors_healthy_ffffa73e; gates attack (0x13a60) and slow recovery (0x13b40).
 */
/* ROM address: 0x000138b2; body bytes: 40; decompiled */

char knock_active_gate(void)

{
  char cVar1;
  
  cVar1 = knock_enable_ffffa73d;
  if ((knock_enable_ffffa73d == '\x01') && (cVar1 = knock_sensors_healthy_ffffa73e, knock_sensors_healthy_ffffa73e == '\x01')) {
    knock_active_ffffa73c = 1;
  }
  else {
    knock_active_ffffa73c = 0;
  }
  return cVar1;
}



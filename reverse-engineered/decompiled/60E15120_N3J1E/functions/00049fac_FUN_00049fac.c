/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_health_persistence [high]: 0xffffa325==0 (no fault) for >30 counts -> cd64=cd66=1; fault 1/2 -> cd67/cd65 with counters cd68/cd6a/cd6c; cleared by DTC 0x23/0x24 active or d1c5.
 * RAM 0xffffa325 knock_sensor_fault_status (uint8): Knock sensor ADC fault: 0 OK, 1/2 per-channel fault (0xc290: ADC 0xffff9f0e vs u16 thresholds 51249/16121 stored at ROM 0x6c17e/0x6c17c).
 * RAM 0xffffcd68 knock_sensor_healthy_counter (uint16): Healthy-count counter (>30 -> cd64/cd66).
 * RAM 0xffffcd6a knock_sensor_fault_counter_a (uint16): Channel A fault counter.
 * RAM 0xffffcd6c knock_sensor_fault_counter_b (uint16): Channel B fault counter.
 */
/* ROM address: 0x00049fac; body bytes: 216; decompiled */

void knock_sensor_health_persistence(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = knock_sensor_fault_status_ffffa325;
  if (DAT_ffffd1c5 == '\0') {
    cVar2 = ref_getFaultStatus__(0x23);
    if ((cVar2 == '\0') && (cVar2 = ref_getFaultStatus__(0x24), cVar2 == '\0')) {
      if (cVar1 != '\x02') {
        if (cVar1 != '\x01') {
          if (0x1e < knock_sensor_healthy_counter_ffffcd68) {
            knock_sensor_healthy_a_ffffcd64 = 1;
            knock_sensor_healthy_b_ffffcd66 = 1;
          }
          knock_sensor_healthy_counter_ffffcd68 = rx8_add_u16_saturate((int)(short)knock_sensor_healthy_counter_ffffcd68,1);
          knock_sensor_fault_counter_a_ffffcd6a = 0;
          knock_sensor_fault_counter_b_ffffcd6c = 0;
          return;
        }
        if (0x1e < knock_sensor_fault_counter_b_ffffcd6c) {
          knock_sensor_fault_b_ffffcd67 = 1;
        }
        knock_sensor_fault_counter_b_ffffcd6c = rx8_add_u16_saturate((int)(short)knock_sensor_fault_counter_b_ffffcd6c,1);
        knock_sensor_healthy_counter_ffffcd68 = 0;
        knock_sensor_fault_counter_a_ffffcd6a = 0;
        return;
      }
      if (0x1e < knock_sensor_fault_counter_a_ffffcd6a) {
        knock_sensor_fault_a_ffffcd65 = 1;
      }
      knock_sensor_fault_counter_a_ffffcd6a = rx8_add_u16_saturate((int)(short)knock_sensor_fault_counter_a_ffffcd6a,1);
    }
    else {
      knock_sensor_fault_counter_a_ffffcd6a = 0;
    }
  }
  else {
    knock_sensor_fault_a_ffffcd65 = 0;
    knock_sensor_fault_b_ffffcd67 = 0;
    knock_sensor_healthy_a_ffffcd64 = 0;
    knock_sensor_healthy_b_ffffcd66 = 0;
    knock_sensor_fault_counter_a_ffffcd6a = 0;
  }
  knock_sensor_fault_counter_b_ffffcd6c = 0;
  knock_sensor_healthy_counter_ffffcd68 = 0;
  return;
}



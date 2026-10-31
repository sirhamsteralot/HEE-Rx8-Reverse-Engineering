/* ROM address: 0x0000c290; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c290 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_knockSensorADCFault(void)

{
  if (DAT_ffff9f0e < 0xc831) {
    if (DAT_ffff9f0e < 0x3ef9) {
      knock_sensor_fault_status_ffffa325 = 2;
    }
    else {
      knock_sensor_fault_status_ffffa325 = 0;
    }
  }
  else {
    knock_sensor_fault_status_ffffa325 = 1;
  }
  return;
}



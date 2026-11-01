/* ROM address: 0x000327d0; body bytes: 34; decompiled */

void apv_command_wrapper(void)

{
  float fVar1;
  
  fVar1 = DAT_ffffbfec;
  if (DAT_ffffbff3 == '\x01') {
    fVar1 = -DAT_ffffbfec;
  }
  apv_duty_split(fVar1 / 100.0);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * secondary_air_pump_control [high]: Writes PBDR_W 0xfffff738 bit 0x4 (PB2, pkg pin 147) = (bf6c == 1): secondary air pump relay/drive output. Called from 0x3174a.
 * RAM 0xffffbf6c secondary_air_pump_request (uint8): Drives PBDR PB2 (pump) and feeds the solenoid condition in 0x187b8.
 */
/* ROM address: 0x000316f8; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00031ba0 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 secondary_air_pump_control(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  char cStack_8;
  
  cStack_8 = secondary_air_pump_request_ffffbf6c;
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff738,4,cStack_8 == '\x01');
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}



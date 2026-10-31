/* ROM address: 0x0000011a; body bytes: 56; decompiled */

uint FUN_0000011a(byte *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    uVar1 = (uVar1 + *param_1 >> 8) + uVar1 + *param_1 & 0xff;
    service_wdt_overflow_and_toggle_pb15();
  }
  return uVar1;
}



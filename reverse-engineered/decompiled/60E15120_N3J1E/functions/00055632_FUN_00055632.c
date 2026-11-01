/* ROM address: 0x00055632; body bytes: 34; decompiled */

uint candidate_diag_read_gear_byte(void)

{
  uint uVar1;
  
  uVar1 = FUN_00061d14();
  if (0xff < (uVar1 & 0xffff)) {
    uVar1 = 0xff;
  }
  return uVar1;
}



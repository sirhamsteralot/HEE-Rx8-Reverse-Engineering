/* ROM address: 0x00055dd6; body bytes: 34; decompiled */

uint FUN_00055dd6(void)

{
  uint uVar1;
  
  uVar1 = FUN_000624b8();
  if (0xff < (uVar1 & 0xffff)) {
    uVar1 = 0xff;
  }
  return uVar1;
}



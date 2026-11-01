/* ROM address: 0x00002478; body bytes: 22; decompiled */

uint FUN_00002478(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xff) + (param_2 & 0xff);
  if (0xfe < uVar1) {
    uVar1 = 0xff;
  }
  return uVar1;
}



/* ROM address: 0x00068b78; body bytes: 24; decompiled */

uint FUN_00068b78(void)

{
  uint uVar1;
  
  uVar1 = (int)DAT_ffffde04 & 0xf0;
  if (0x3f < uVar1) {
    uVar1 = 0x40;
  }
  return uVar1;
}



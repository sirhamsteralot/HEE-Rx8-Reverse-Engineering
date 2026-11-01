/* ROM address: 0x00029dc6; body bytes: 62; decompiled */

uint can201_encode_rpm_u16(void)

{
  uint uVar1;
  
  if (DAT_ffffcdfc == '\x01') {
    DAT_ffffbb64 = 0xffff;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_00002490(DAT_ffffbb6c,0x3e800000,0);
    if ((undefined *)(uVar1 & 0xffff) < (undefined *)0xffff) {
      DAT_ffffbb64 = (undefined2)uVar1;
    }
    else {
      DAT_ffffbb64 = 0xfffe;
    }
  }
  return uVar1;
}



/* ROM address: 0x0004f4e0; body bytes: 68; decompiled */

uint FUN_0004f4e0(void)

{
  uint uVar1;
  
  if (DAT_ffffcffd == '\x01') {
    DAT_ffffcff8 = 0;
    uVar1 = 1;
  }
  else if (((DAT_ffffcffa == '\x01') &&
           (uVar1 = (uint)DAT_ffffcfe6, (uint)(int)DAT_ffffcfe2 <= uVar1)) ||
          (uVar1 = (uint)DAT_ffffd198, uVar1 == 1)) {
    DAT_ffffcff8 = 1;
  }
  else {
    DAT_ffffcff8 = 0;
  }
  return uVar1;
}



/* ROM address: 0x0004f524; body bytes: 68; decompiled */

uint FUN_0004f524(void)

{
  uint uVar1;
  
  if (DAT_ffffcffe == '\x01') {
    DAT_ffffcff9 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcffa;
    if (((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfe6, (uint)(int)DAT_ffffcfe4 <= uVar1)) ||
       (DAT_ffffd27c != 0)) {
      DAT_ffffcff9 = 1;
    }
    else {
      DAT_ffffcff9 = 0;
    }
  }
  return uVar1;
}



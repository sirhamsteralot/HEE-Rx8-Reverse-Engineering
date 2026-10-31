/* ROM address: 0x0004ed80; body bytes: 68; decompiled */

uint FUN_0004ed80(void)

{
  uint uVar1;
  
  if (DAT_ffffcfc2 == '\x01') {
    DAT_ffffcfbd = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcfbe;
    if (((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfaa, (uint)(int)DAT_ffffcfa8 <= uVar1)) ||
       (DAT_ffffd240 != 0)) {
      DAT_ffffcfbd = 1;
    }
    else {
      DAT_ffffcfbd = 0;
    }
  }
  return uVar1;
}



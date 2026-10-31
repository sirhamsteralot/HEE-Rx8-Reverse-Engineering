/* ROM address: 0x0004ed3c; body bytes: 68; decompiled */

uint FUN_0004ed3c(void)

{
  uint uVar1;
  
  if (DAT_ffffcfc1 == '\x01') {
    DAT_ffffcfbc = 0;
    uVar1 = 1;
  }
  else if (((DAT_ffffcfbe == '\x01') &&
           (uVar1 = (uint)DAT_ffffcfaa, (uint)(int)DAT_ffffcfa6 <= uVar1)) ||
          (uVar1 = (uint)DAT_ffffd15c, uVar1 == 1)) {
    DAT_ffffcfbc = 1;
  }
  else {
    DAT_ffffcfbc = 0;
  }
  return uVar1;
}



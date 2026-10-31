/* ROM address: 0x0004ad8c; body bytes: 44; decompiled */

uint FUN_0004ad8c(void)

{
  uint uVar1;
  
  if (DAT_ffffcdbc == '\x01') {
    uVar1 = FUN_0005fd38(0x26,1);
    return uVar1;
  }
  if (DAT_ffffcdbd == 1) {
    uVar1 = FUN_0005fd38(0x26,2);
    return uVar1;
  }
  return (uint)DAT_ffffcdbd;
}



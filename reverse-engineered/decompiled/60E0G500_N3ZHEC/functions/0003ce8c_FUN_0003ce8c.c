/* ROM address: 0x0003ce8c; body bytes: 44; decompiled */

uint FUN_0003ce8c(void)

{
  uint uVar1;
  
  if (DAT_ffffc623 == '\x01') {
    uVar1 = FUN_000604dc(0x33,1);
    return uVar1;
  }
  if (DAT_ffffc624 == 1) {
    uVar1 = FUN_000604dc(0x33,2);
    return uVar1;
  }
  return (uint)DAT_ffffc624;
}



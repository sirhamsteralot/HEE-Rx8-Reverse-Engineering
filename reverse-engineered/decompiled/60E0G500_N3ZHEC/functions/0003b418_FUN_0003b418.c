/* ROM address: 0x0003b418; body bytes: 44; decompiled */

uint FUN_0003b418(void)

{
  uint uVar1;
  
  if (DAT_ffffc5b2 == '\x01') {
    uVar1 = FUN_000604dc(0x2b,1);
    return uVar1;
  }
  if (DAT_ffffc5b3 == 1) {
    uVar1 = FUN_000604dc(0x2b,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5b3;
}



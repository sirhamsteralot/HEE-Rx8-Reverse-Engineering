/* ROM address: 0x0003999e; body bytes: 44; decompiled */

uint FUN_0003999e(void)

{
  uint uVar1;
  
  if (DAT_ffffc575 == '\x01') {
    uVar1 = FUN_000604dc(0x17,1);
    return uVar1;
  }
  if (DAT_ffffc576 == 1) {
    uVar1 = FUN_000604dc(0x17,2);
    return uVar1;
  }
  return (uint)DAT_ffffc576;
}



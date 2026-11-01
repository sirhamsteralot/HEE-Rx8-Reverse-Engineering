/* ROM address: 0x0003c102; body bytes: 44; decompiled */

uint FUN_0003c102(void)

{
  uint uVar1;
  
  if (DAT_ffffc5f1 == '\x01') {
    uVar1 = FUN_000604dc(0x2f,1);
    return uVar1;
  }
  if (DAT_ffffc5f2 == 1) {
    uVar1 = FUN_000604dc(0x2f,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5f2;
}



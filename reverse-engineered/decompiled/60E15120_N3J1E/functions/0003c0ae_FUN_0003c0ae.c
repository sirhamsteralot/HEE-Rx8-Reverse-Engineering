/* ROM address: 0x0003c0ae; body bytes: 44; decompiled */

uint FUN_0003c0ae(void)

{
  uint uVar1;
  
  if (DAT_ffffc5c5 == '\x01') {
    uVar1 = FUN_0005fd38(0x3e,1);
    return uVar1;
  }
  if (DAT_ffffc5c6 == 1) {
    uVar1 = FUN_0005fd38(0x3e,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5c6;
}



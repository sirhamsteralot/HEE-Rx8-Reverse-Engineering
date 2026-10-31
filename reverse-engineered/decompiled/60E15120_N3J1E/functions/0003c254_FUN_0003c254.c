/* ROM address: 0x0003c254; body bytes: 44; decompiled */

uint FUN_0003c254(void)

{
  uint uVar1;
  
  if (DAT_ffffc5cc == '\x01') {
    uVar1 = FUN_0005fd38(0x25,1);
    return uVar1;
  }
  if (DAT_ffffc5cb == 1) {
    uVar1 = FUN_0005fd38(0x25,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5cb;
}



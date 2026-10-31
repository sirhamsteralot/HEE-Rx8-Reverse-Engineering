/* ROM address: 0x0003bf3c; body bytes: 44; decompiled */

uint FUN_0003bf3c(void)

{
  uint uVar1;
  
  if (DAT_ffffc5b3 == '\x01') {
    uVar1 = FUN_0005fd38(0x33,1);
    return uVar1;
  }
  if (DAT_ffffc5b4 == 1) {
    uVar1 = FUN_0005fd38(0x33,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5b4;
}



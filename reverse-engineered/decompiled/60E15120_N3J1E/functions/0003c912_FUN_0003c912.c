/* ROM address: 0x0003c912; body bytes: 44; decompiled */

uint FUN_0003c912(void)

{
  uint uVar1;
  
  if (DAT_ffffc5e1 == '\x01') {
    uVar1 = FUN_0005fd38(0xe,1);
    return uVar1;
  }
  if (DAT_ffffc5e2 == 1) {
    uVar1 = FUN_0005fd38(0xe,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5e2;
}



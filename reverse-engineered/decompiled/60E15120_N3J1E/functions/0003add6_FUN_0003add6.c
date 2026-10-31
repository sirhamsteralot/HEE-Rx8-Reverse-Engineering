/* ROM address: 0x0003add6; body bytes: 44; decompiled */

uint FUN_0003add6(void)

{
  uint uVar1;
  
  if (DAT_ffffc574 == '\x01') {
    uVar1 = FUN_0005fd38(0x38,1);
    return uVar1;
  }
  if (DAT_ffffc575 == 1) {
    uVar1 = FUN_0005fd38(0x38,2);
    return uVar1;
  }
  return (uint)DAT_ffffc575;
}



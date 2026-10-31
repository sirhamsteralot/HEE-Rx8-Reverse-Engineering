/* ROM address: 0x0003a4c8; body bytes: 44; decompiled */

uint FUN_0003a4c8(void)

{
  uint uVar1;
  
  if (DAT_ffffc542 == '\x01') {
    uVar1 = FUN_0005fd38(0x2b,1);
    return uVar1;
  }
  if (DAT_ffffc543 == 1) {
    uVar1 = FUN_0005fd38(0x2b,2);
    return uVar1;
  }
  return (uint)DAT_ffffc543;
}



/* ROM address: 0x0003e6c4; body bytes: 44; decompiled */

uint FUN_0003e6c4(void)

{
  uint uVar1;
  
  if (DAT_ffffc698 == '\x01') {
    uVar1 = FUN_000604dc(0x4b,1);
    return uVar1;
  }
  if (DAT_ffffc699 == 1) {
    uVar1 = FUN_000604dc(0x4b,2);
    return uVar1;
  }
  return (uint)DAT_ffffc699;
}



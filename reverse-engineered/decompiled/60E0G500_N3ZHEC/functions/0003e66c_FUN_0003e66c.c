/* ROM address: 0x0003e66c; body bytes: 44; decompiled */

uint FUN_0003e66c(void)

{
  uint uVar1;
  
  if (DAT_ffffc69a == '\x01') {
    uVar1 = FUN_000604dc(0x4c,1);
    return uVar1;
  }
  if (DAT_ffffc69b == 1) {
    uVar1 = FUN_000604dc(0x4c,2);
    return uVar1;
  }
  return (uint)DAT_ffffc69b;
}



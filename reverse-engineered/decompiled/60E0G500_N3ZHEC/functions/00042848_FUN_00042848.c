/* ROM address: 0x00042848; body bytes: 44; decompiled */

uint FUN_00042848(void)

{
  uint uVar1;
  
  if (DAT_ffffc98d == '\x01') {
    uVar1 = FUN_000604dc(2,1);
    return uVar1;
  }
  if (DAT_ffffc98c == 1) {
    uVar1 = FUN_000604dc(2);
    return uVar1;
  }
  return (uint)DAT_ffffc98c;
}



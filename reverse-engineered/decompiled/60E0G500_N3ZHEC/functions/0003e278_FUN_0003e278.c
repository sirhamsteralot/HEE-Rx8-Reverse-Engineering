/* ROM address: 0x0003e278; body bytes: 44; decompiled */

uint FUN_0003e278(void)

{
  uint uVar1;
  
  if (DAT_ffffc686 == '\x01') {
    uVar1 = FUN_000604dc(0x4a,1);
    return uVar1;
  }
  if (DAT_ffffc687 == 1) {
    uVar1 = FUN_000604dc(0x4a,2);
    return uVar1;
  }
  return (uint)DAT_ffffc687;
}



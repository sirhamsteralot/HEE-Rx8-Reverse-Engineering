/* ROM address: 0x0003cffe; body bytes: 44; decompiled */

uint FUN_0003cffe(void)

{
  uint uVar1;
  
  if (DAT_ffffc635 == '\x01') {
    uVar1 = FUN_000604dc(0x3e,1);
    return uVar1;
  }
  if (DAT_ffffc636 == 1) {
    uVar1 = FUN_000604dc(0x3e,2);
    return uVar1;
  }
  return (uint)DAT_ffffc636;
}



/* ROM address: 0x0003bd26; body bytes: 44; decompiled */

uint FUN_0003bd26(void)

{
  uint uVar1;
  
  if (DAT_ffffc5e4 == '\x01') {
    uVar1 = FUN_000604dc(0x38,1);
    return uVar1;
  }
  if (DAT_ffffc5e5 == 1) {
    uVar1 = FUN_000604dc(0x38,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5e5;
}



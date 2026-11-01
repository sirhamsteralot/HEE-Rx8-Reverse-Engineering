/* ROM address: 0x0003bd52; body bytes: 44; decompiled */

uint FUN_0003bd52(void)

{
  uint uVar1;
  
  if (DAT_ffffc5e8 == '\x01') {
    uVar1 = FUN_000604dc(0x39,1);
    return uVar1;
  }
  if (DAT_ffffc5e9 == 1) {
    uVar1 = FUN_000604dc(0x39,2);
    return uVar1;
  }
  return (uint)DAT_ffffc5e9;
}



/* ROM address: 0x0003e9aa; body bytes: 44; decompiled */

uint FUN_0003e9aa(void)

{
  uint uVar1;
  
  if (DAT_ffffc6a5 == '\x01') {
    uVar1 = FUN_000604dc(0x58,1);
    return uVar1;
  }
  if (DAT_ffffc6a6 == 1) {
    uVar1 = FUN_000604dc(0x58,2);
    return uVar1;
  }
  return (uint)DAT_ffffc6a6;
}



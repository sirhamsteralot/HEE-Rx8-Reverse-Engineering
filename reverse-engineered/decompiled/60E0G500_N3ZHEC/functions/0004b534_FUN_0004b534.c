/* ROM address: 0x0004b534; body bytes: 44; decompiled */

uint FUN_0004b534(void)

{
  uint uVar1;
  
  if (DAT_ffffcdfc == '\x01') {
    uVar1 = FUN_000604dc(0x26,1);
    return uVar1;
  }
  if (DAT_ffffcdfd == 1) {
    uVar1 = FUN_000604dc(0x26,2);
    return uVar1;
  }
  return (uint)DAT_ffffcdfd;
}



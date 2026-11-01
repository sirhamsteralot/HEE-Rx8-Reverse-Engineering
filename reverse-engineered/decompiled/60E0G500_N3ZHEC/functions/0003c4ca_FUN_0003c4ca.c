/* ROM address: 0x0003c4ca; body bytes: 44; decompiled */

uint FUN_0003c4ca(void)

{
  uint uVar1;
  
  if (DAT_ffffc606 == '\x01') {
    uVar1 = FUN_000604dc(9,1);
    return uVar1;
  }
  if (DAT_ffffc607 == 1) {
    uVar1 = FUN_000604dc(9,2);
    return uVar1;
  }
  return (uint)DAT_ffffc607;
}



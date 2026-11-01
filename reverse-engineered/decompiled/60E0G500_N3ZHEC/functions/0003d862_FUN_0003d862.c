/* ROM address: 0x0003d862; body bytes: 44; decompiled */

uint FUN_0003d862(void)

{
  uint uVar1;
  
  if (DAT_ffffc651 == '\x01') {
    uVar1 = FUN_000604dc(0xe,1);
    return uVar1;
  }
  if (DAT_ffffc652 == 1) {
    uVar1 = FUN_000604dc(0xe,2);
    return uVar1;
  }
  return (uint)DAT_ffffc652;
}



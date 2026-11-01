/* ROM address: 0x0003d1a4; body bytes: 44; decompiled */

uint FUN_0003d1a4(void)

{
  uint uVar1;
  
  if (DAT_ffffc63c == '\x01') {
    uVar1 = FUN_000604dc(0x25,1);
    return uVar1;
  }
  if (DAT_ffffc63b == 1) {
    uVar1 = FUN_000604dc(0x25,2);
    return uVar1;
  }
  return (uint)DAT_ffffc63b;
}



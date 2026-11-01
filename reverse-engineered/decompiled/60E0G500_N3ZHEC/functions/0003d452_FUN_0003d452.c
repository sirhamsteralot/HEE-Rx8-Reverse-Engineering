/* ROM address: 0x0003d452; body bytes: 92; decompiled */

uint FUN_0003d452(void)

{
  uint uVar1;
  
  if (DAT_ffffc644 == '\x01') {
    FUN_000604dc(0xc,1);
  }
  else if (DAT_ffffc646 == 1) {
    FUN_000604dc(0xc,2);
  }
  if (DAT_ffffc645 == '\x01') {
    uVar1 = FUN_000604dc(0xd,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc646;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0xd,2);
    }
  }
  return uVar1;
}



/* ROM address: 0x0003ceb8; body bytes: 172; decompiled */

uint FUN_0003ceb8(void)

{
  uint uVar1;
  
  if (DAT_ffffc61f == '\x01') {
    FUN_000604dc(0x34,1);
  }
  else if (DAT_ffffc622 == '\x01') {
    FUN_000604dc(0x34,2);
  }
  if (DAT_ffffc620 == '\x01') {
    FUN_000604dc(0x36,1);
  }
  else if (DAT_ffffc622 == '\x01') {
    FUN_000604dc(0x36,2);
  }
  if (DAT_ffffc62b == '\x01') {
    FUN_000604dc(0x35,1);
  }
  else if (DAT_ffffc62e == 1) {
    FUN_000604dc(0x35,2);
  }
  if (DAT_ffffc62c == '\x01') {
    uVar1 = FUN_000604dc(0x37,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc62e;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x37,2);
    }
  }
  return uVar1;
}



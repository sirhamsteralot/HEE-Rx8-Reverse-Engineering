/* ROM address: 0x0004006e; body bytes: 132; decompiled */

uint FUN_0004006e(void)

{
  uint uVar1;
  
  if (DAT_ffffc729 == '\x01') {
    FUN_000604dc(0x73,1);
  }
  else if (DAT_ffffc728 == '\x01') {
    FUN_000604dc(0x73,2);
  }
  if (DAT_ffffc72b == '\x01') {
    FUN_000604dc(0x74,1);
  }
  else if (DAT_ffffc72a == '\x01') {
    FUN_000604dc(0x74,2);
  }
  if (DAT_ffffc72d == '\x01') {
    uVar1 = FUN_000604dc(0x1d,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc72c;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x1d,2);
    }
  }
  return uVar1;
}



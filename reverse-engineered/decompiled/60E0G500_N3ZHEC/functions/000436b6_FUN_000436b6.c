/* ROM address: 0x000436b6; body bytes: 132; decompiled */

uint FUN_000436b6(void)

{
  uint uVar1;
  
  if (DAT_ffffc9dd == '\x01') {
    FUN_000604dc(0x1b,1);
  }
  else if (DAT_ffffc9dc == '\x01') {
    FUN_000604dc(0x1b,2);
  }
  if (DAT_ffffc9df == '\x01') {
    FUN_000604dc(0x1a,1);
  }
  else if (DAT_ffffc9de == '\x01') {
    FUN_000604dc(0x1a,2);
  }
  if (DAT_ffffc9e1 == '\x01') {
    uVar1 = FUN_000604dc(0x19,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc9e0;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x19,2);
    }
  }
  return uVar1;
}



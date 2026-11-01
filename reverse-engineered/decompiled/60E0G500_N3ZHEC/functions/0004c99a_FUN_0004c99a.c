/* ROM address: 0x0004c99a; body bytes: 212; decompiled */

uint FUN_0004c99a(void)

{
  uint uVar1;
  
  if (DAT_ffffced8 == '\x01') {
    FUN_000604dc(0x54,1);
  }
  else if (DAT_ffffced9 == '\x01') {
    FUN_000604dc(0x54,2);
  }
  if (DAT_ffffced6 == '\x01') {
    FUN_000604dc(0x55,1);
  }
  else if (DAT_ffffced9 == '\x01') {
    FUN_000604dc(0x55,2);
  }
  if (DAT_ffffced7 == '\x01') {
    FUN_000604dc(0x56,1);
  }
  else if (DAT_ffffced9 == '\x01') {
    FUN_000604dc(0x56,2);
  }
  if (DAT_ffffcee6 == '\x01') {
    FUN_000604dc(0x53,1);
  }
  else if (DAT_ffffcee7 == '\x01') {
    FUN_000604dc(0x53,2);
  }
  if (DAT_ffffcee5 == '\x01') {
    uVar1 = FUN_000604dc(0x57,1);
  }
  else {
    uVar1 = (uint)DAT_ffffcee4;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x57,2);
    }
  }
  return uVar1;
}



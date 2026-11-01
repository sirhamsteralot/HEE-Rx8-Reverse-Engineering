/* ROM address: 0x0004aff6; body bytes: 92; decompiled */

uint FUN_0004aff6(void)

{
  uint uVar1;
  
  if (DAT_ffffcdbc == '\x01') {
    FUN_000604dc(0x59,1);
  }
  else if (DAT_ffffcdc1 == '\x01') {
    FUN_000604dc(0x59,2);
  }
  if (DAT_ffffcdbe == '\x01') {
    uVar1 = FUN_000604dc(0x5a,1);
  }
  else {
    uVar1 = (uint)DAT_ffffcdc0;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x5a,2);
    }
  }
  return uVar1;
}



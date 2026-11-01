/* ROM address: 0x000438b8; body bytes: 92; decompiled */

uint FUN_000438b8(void)

{
  uint uVar1;
  
  if (DAT_ffffca05 == '\x01') {
    FUN_000604dc(5,1);
  }
  else if (DAT_ffffca04 == '\x01') {
    FUN_000604dc(5,2);
  }
  if (DAT_ffffca07 == '\x01') {
    uVar1 = FUN_000604dc(6,1);
  }
  else {
    uVar1 = (uint)DAT_ffffca06;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(6,2);
    }
  }
  return uVar1;
}



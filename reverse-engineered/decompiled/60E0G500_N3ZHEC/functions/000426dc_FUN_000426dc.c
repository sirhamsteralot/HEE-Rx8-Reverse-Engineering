/* ROM address: 0x000426dc; body bytes: 92; decompiled */

uint FUN_000426dc(void)

{
  uint uVar1;
  
  if (DAT_ffffc982 == '\x01') {
    FUN_000604dc(3,1);
  }
  else if (DAT_ffffc981 == '\x01') {
    FUN_000604dc(3,2);
  }
  if (DAT_ffffc984 == '\x01') {
    uVar1 = FUN_000604dc(4,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc983;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(4,2);
    }
  }
  return uVar1;
}



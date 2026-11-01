/* ROM address: 0x0004fa2e; body bytes: 52; decompiled */

uint FUN_0004fa2e(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcfe6 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcffa;
    if (uVar1 == 1) {
      uVar1 = FUN_00002460((int)DAT_ffffcfe6,1);
      DAT_ffffcfe6 = (short)uVar1;
    }
  }
  return uVar1;
}



/* ROM address: 0x00039972; body bytes: 44; decompiled */

uint FUN_00039972(void)

{
  uint uVar1;
  
  if (DAT_ffffc570 == '\x01') {
    uVar1 = FUN_000604dc(0x18,1);
    return uVar1;
  }
  if (DAT_ffffc571 == 1) {
    uVar1 = FUN_000604dc(0x18,2);
    return uVar1;
  }
  return (uint)DAT_ffffc571;
}



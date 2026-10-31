/* ROM address: 0x000389b6; body bytes: 44; decompiled */

uint FUN_000389b6(void)

{
  uint uVar1;
  
  if (DAT_ffffc505 == '\x01') {
    uVar1 = FUN_0005fd38(0x17,1);
    return uVar1;
  }
  if (DAT_ffffc506 == 1) {
    uVar1 = FUN_0005fd38(0x17,2);
    return uVar1;
  }
  return (uint)DAT_ffffc506;
}



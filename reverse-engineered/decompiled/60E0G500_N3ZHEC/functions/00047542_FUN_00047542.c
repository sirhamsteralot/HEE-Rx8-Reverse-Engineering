/* ROM address: 0x00047542; body bytes: 56; decompiled */

uint FUN_00047542(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8770,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x44,1);
    return uVar1;
  }
  if (DAT_ffffcca4 == 1) {
    uVar1 = FUN_000604dc(0x44,2);
    return uVar1;
  }
  return (uint)DAT_ffffcca4;
}



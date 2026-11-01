/* ROM address: 0x000476e0; body bytes: 56; decompiled */

uint FUN_000476e0(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8778,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x41,1);
    return uVar1;
  }
  if (DAT_ffffcca8 == 1) {
    uVar1 = FUN_000604dc(0x41,2);
    return uVar1;
  }
  return (uint)DAT_ffffcca8;
}



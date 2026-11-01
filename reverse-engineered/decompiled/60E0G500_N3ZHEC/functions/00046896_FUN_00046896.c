/* ROM address: 0x00046896; body bytes: 110; decompiled */

uint FUN_00046896(void)

{
  char cVar2;
  uint uVar1;
  
  if (DAT_ffffcc4c == '\x01') {
    if (0x18 < DAT_ffffcc4e) {
      FUN_0003ebc0(&DAT_ffff8760,1);
    }
    if (0xf9 < DAT_ffffcc50) {
      DAT_ffffcc4d = 1;
    }
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8760,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x85,1);
    return uVar1;
  }
  if (DAT_ffffcc4d == 1) {
    uVar1 = FUN_000604dc(0x85,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc4d;
}



/* ROM address: 0x00047d18; body bytes: 98; decompiled */

uint FUN_00047d18(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8786,0);
  if (cVar2 == '\x01') {
    FUN_0006053a();
    FUN_0003ebc0(&DAT_ffff8786,0);
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8788,1);
  if ((cVar2 == '\x01') && (cVar2 = FUN_0003eaa4(&DAT_ffff8784,0), cVar2 == '\x01')) {
    DAT_ffffcce4 = 1;
  }
  if (DAT_ffffcce4 == 1) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8784,0);
    return uVar1;
  }
  return (uint)DAT_ffffcce4;
}



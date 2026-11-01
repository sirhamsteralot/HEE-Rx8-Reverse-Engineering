/* ROM address: 0x000475b0; body bytes: 194; decompiled */

uint FUN_000475b0(void)

{
  undefined4 uVar1;
  char cVar4;
  uint uVar2;
  short sVar3;
  
  uVar1 = FUN_0003eae4(&DAT_ffff877c,0);
  cVar4 = FUN_0003eaa4(&DAT_ffff8788,1);
  if (cVar4 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8778,0);
    uVar1 = 0;
  }
  else {
    cVar4 = FUN_0003eaa4(&DAT_ffff877a,0);
    if (cVar4 == '\x01') {
      uVar1 = FUN_00002460(uVar1,1);
    }
  }
  FUN_0003ebd0(&DAT_ffff877c,uVar1);
  FUN_0000d2f6(0);
  uVar2 = FUN_0000d3b8();
  uVar2 = uVar2 & 0xff;
  if (uVar2 == 1) {
    sVar3 = FUN_0003eae4(&DAT_ffff877c,0);
    if (sVar3 == 0) {
      sVar3 = -0x7886;
    }
    else {
      FUN_0003ebc0(&DAT_ffff877a,0);
      sVar3 = -0x7888;
    }
    uVar2 = FUN_0003ebc0((int)sVar3,1);
  }
  else if (uVar2 == 0) {
    uVar2 = FUN_0003ebc0(&DAT_ffff877a,0);
    DAT_ffffcca8 = 1;
  }
  return uVar2;
}



/* ROM address: 0x00052834; body bytes: 398; decompiled */

uint FUN_00052834(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  
  bVar3 = DAT_ffffd148;
  uVar7 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd160 = FUN_000020ac(uVar7,&DAT_0006b8ec);
  bVar4 = FUN_00011f34();
  cVar2 = DAT_ffffd079;
  if (DAT_ffffd079 == '\x01') {
    FUN_0003ebc0(&DAT_ffff86f8,0);
    FUN_0003ebc0(&DAT_ffff86f6,0);
  }
  else {
    if (((DAT_ffffcffb == '\x01') && (DAT_ffffcfe4 < DAT_ffffcfe6)) && (DAT_ffffd161 != bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (((bVar1) && (bVar3 < DAT_ffffd160)) || (DAT_ffffd183 == '\x01')) {
      FUN_0003ebc0(&DAT_ffff86f6,1);
    }
    if ((bVar1) && (DAT_ffffd160 <= bVar3)) {
      FUN_0003ebc0(&DAT_ffff86f8,1);
    }
  }
  if ((DAT_ffffd075 == '\x01') || (DAT_ffffcfb4 == '\x01')) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  if (DAT_ffffd07a == '\x01') {
    DAT_ffffd153 = 0;
  }
  else if (((uVar6 == 1) && (cVar5 = FUN_0003eaa4(&DAT_ffff86f6,0), cVar5 == '\x01')) &&
          (cVar5 = FUN_000671a4(0x77), cVar5 == '\0')) {
    DAT_ffffd153 = 1;
  }
  if (cVar2 == '\x01') {
    DAT_ffffd154 = 0;
    uVar6 = 1;
  }
  else if (uVar6 == 1) {
    uVar6 = FUN_0003eaa4(&DAT_ffff86f8,0);
    uVar6 = uVar6 & 0xff;
    if (uVar6 == 1) {
      uVar6 = FUN_000671a4(0x77);
      uVar6 = uVar6 & 0xff;
      if (uVar6 == 0) {
        DAT_ffffd154 = 1;
      }
    }
  }
  if ((DAT_ffffd163 == '\0') && (uVar6 = (uint)bVar4, uVar6 == 1)) {
    FUN_0003ebc0(&DAT_ffff86f6,0);
    uVar6 = FUN_0003ebc0(&DAT_ffff86f8,0);
  }
  DAT_ffffd161 = bVar3;
  DAT_ffffd163 = bVar4;
  return uVar6;
}



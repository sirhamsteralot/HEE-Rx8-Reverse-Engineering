/* ROM address: 0x00052c1a; body bytes: 492; decompiled */

uint FUN_00052c1a(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  float fVar7;
  
  uVar2 = DAT_ffffcfe6;
  uVar1 = DAT_ffffcfe4;
  fVar7 = DAT_ffffd01c;
  bVar4 = FUN_00011f34();
  cVar3 = DAT_ffffd079;
  if (DAT_ffffd079 == '\x01') {
    FUN_0003ebc0(&DAT_ffff86fe,0);
    FUN_0003ebc0(&DAT_ffff8700,0);
    FUN_0003ebc0(&DAT_ffff8702,0);
  }
  else if ((DAT_ffffcffb == '\x01') &&
          ((((DAT_ffffcfe2 < uVar2 && (uVar2 <= uVar1)) && (DAT_ffffd034 == '\0')) ||
           ((uVar1 < uVar2 &&
            (((DAT_ffffd002 == '\x01' && (DAT_ffffd001 == '\0')) ||
             ((DAT_ffffd12e == '\x01' && (uVar2 < 0x88)))))))))) {
    if (fVar7 < 0.001) {
      FUN_0003ebc0(&DAT_ffff86fe,1);
    }
    if (0.03207 < fVar7) {
      FUN_0003ebc0(&DAT_ffff8700,1);
    }
    if ((fVar7 <= 0.03207) && (0.001 <= fVar7)) {
      FUN_0003ebc0(&DAT_ffff8702,1);
    }
  }
  if ((DAT_ffffd075 == '\x01') || (DAT_ffffcfb4 == '\x01')) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  if (DAT_ffffd07a == '\x01') {
    DAT_ffffd14b = 0;
    DAT_ffffd14c = 0;
  }
  else if (uVar6 == 1) {
    cVar5 = FUN_0003eaa4(&DAT_ffff86fe,0);
    if ((cVar5 == '\x01') && (cVar5 = FUN_000671a4(0x75), cVar5 == '\0')) {
      DAT_ffffd14b = 1;
    }
    cVar5 = FUN_0003eaa4(&DAT_ffff8700,0);
    if ((cVar5 == '\x01') && (cVar5 = FUN_000671a4(0x76), cVar5 == '\0')) {
      DAT_ffffd14c = 1;
    }
  }
  if (cVar3 == '\x01') {
    DAT_ffffd14d = 0;
    uVar6 = 1;
  }
  else if (uVar6 == 1) {
    uVar6 = FUN_0003eaa4(&DAT_ffff8702,0);
    uVar6 = uVar6 & 0xff;
    if (uVar6 == 1) {
      uVar6 = FUN_000671a4(0x75);
      uVar6 = uVar6 & 0xff;
      if (uVar6 == 0) {
        uVar6 = FUN_000671a4(0x76);
        uVar6 = uVar6 & 0xff;
        if (uVar6 == 0) {
          DAT_ffffd14d = 1;
        }
      }
    }
  }
  if ((DAT_ffffd165 == '\0') && (uVar6 = (uint)bVar4, uVar6 == 1)) {
    FUN_0003ebc0(&DAT_ffff86fe,0);
    FUN_0003ebc0(&DAT_ffff8700,0);
    uVar6 = FUN_0003ebc0(&DAT_ffff8702,0);
  }
  DAT_ffffd165 = bVar4;
  return uVar6;
}



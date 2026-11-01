/* ROM address: 0x00052a60; body bytes: 332; decompiled */

uint FUN_00052a60(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  
  fVar5 = DAT_ffffd020 - DAT_ffffd024;
  bVar2 = FUN_00011f34();
  cVar1 = DAT_ffffd079;
  if (DAT_ffffd079 == '\x01') {
    FUN_0003ebc0(&DAT_ffff86fa,0);
    FUN_0003ebc0(&DAT_ffff86fc,0);
  }
  else if (((DAT_ffffcffb == '\x01') && (DAT_ffffcfe4 < DAT_ffffcfe6)) && (DAT_ffffd034 == '\0')) {
    if (fVar5 < 0.0019) {
      FUN_0003ebc0(&DAT_ffff86fa,1);
    }
    if (0.0019 <= fVar5) {
      FUN_0003ebc0(&DAT_ffff86fc,1);
    }
  }
  if ((DAT_ffffd075 == '\x01') || (DAT_ffffcfb4 == '\x01')) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  if (DAT_ffffd07a == '\x01') {
    DAT_ffffd151 = 0;
  }
  else if (((uVar4 == 1) && (cVar3 = FUN_0003eaa4(&DAT_ffff86fa,0), cVar3 == '\x01')) &&
          (cVar3 = FUN_000671a4(0x30), cVar3 == '\0')) {
    DAT_ffffd151 = 1;
  }
  if (cVar1 == '\x01') {
    DAT_ffffd152 = 0;
    uVar4 = 1;
  }
  else if (uVar4 == 1) {
    uVar4 = FUN_0003eaa4(&DAT_ffff86fc,0);
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 1) {
      uVar4 = FUN_000671a4(0x30);
      uVar4 = uVar4 & 0xff;
      if (uVar4 == 0) {
        DAT_ffffd152 = 1;
      }
    }
  }
  if ((DAT_ffffd164 == '\0') && (uVar4 = (uint)bVar2, uVar4 == 1)) {
    FUN_0003ebc0(&DAT_ffff86fa,0);
    uVar4 = FUN_0003ebc0(&DAT_ffff86fc,0);
  }
  DAT_ffffd164 = bVar2;
  return uVar4;
}



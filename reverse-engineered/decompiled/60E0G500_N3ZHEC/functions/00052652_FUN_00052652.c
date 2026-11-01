/* ROM address: 0x00052652; body bytes: 380; decompiled */

uint FUN_00052652(void)

{
  byte bVar2;
  uint uVar1;
  char cVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = DAT_ffffd028;
  fVar5 = DAT_ffffd02c;
  DAT_ffffd15c = (float)FUN_00002068(DAT_ffffb600,&DAT_0006b90c);
  DAT_ffffd158 = (float)FUN_00002068(DAT_ffffb600,&DAT_0006b8f8);
  bVar2 = FUN_00011f34();
  if (DAT_ffffd079 == '\x01') {
    DAT_ffffd14e = 0;
    DAT_ffffd14f = 0;
    DAT_ffffd150 = 0;
    FUN_0003ebc0(&DAT_ffff86f0,0);
    FUN_0003ebc0(&DAT_ffff86f2,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff86f4,0);
  }
  else {
    if ((DAT_ffffcffb == '\x01') && (DAT_ffffcfe6 == DAT_ffffcfe4)) {
      if (fVar5 < DAT_ffffd15c) {
        FUN_0003ebc0(&DAT_ffff86f0,1);
      }
      if (DAT_ffffd158 < fVar4) {
        FUN_0003ebc0(&DAT_ffff86f2,1);
      }
      if ((fVar4 <= DAT_ffffd158) && (DAT_ffffd15c <= fVar5)) {
        FUN_0003ebc0(&DAT_ffff86f4,1);
      }
    }
    if ((DAT_ffffd075 == '\x01') || (uVar1 = (uint)DAT_ffffcfb4, uVar1 == 1)) {
      cVar3 = FUN_0003eaa4(&DAT_ffff86f0,0);
      if ((cVar3 == '\x01') && (cVar3 = FUN_000671a4(0x78), cVar3 == '\0')) {
        DAT_ffffd14e = 1;
      }
      cVar3 = FUN_0003eaa4(&DAT_ffff86f2,0);
      if ((cVar3 == '\x01') && (cVar3 = FUN_000671a4(0x79), cVar3 == '\0')) {
        DAT_ffffd14f = 1;
      }
      uVar1 = FUN_0003eaa4(&DAT_ffff86f4,0);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 1) {
        uVar1 = FUN_000671a4(0x78);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          uVar1 = FUN_000671a4(0x79);
          uVar1 = uVar1 & 0xff;
          if (uVar1 == 0) {
            DAT_ffffd150 = 1;
          }
        }
      }
    }
    if ((DAT_ffffd162 == '\0') && (uVar1 = (uint)bVar2, uVar1 == 1)) {
      FUN_0003ebc0(&DAT_ffff86f0,0);
      FUN_0003ebc0(&DAT_ffff86f2,0);
      uVar1 = FUN_0003ebc0(&DAT_ffff86f4,0);
    }
  }
  DAT_ffffd162 = bVar2;
  return uVar1;
}



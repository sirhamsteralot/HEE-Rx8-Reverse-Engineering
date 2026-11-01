/* ROM address: 0x000517ee; body bytes: 490; decompiled */

uint FUN_000517ee(void)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  uVar1 = DAT_ffffd0e0;
  uVar7 = 0;
  uVar4 = FUN_0003eb72(0,&DAT_ffff86a4);
  fVar5 = (float)FUN_0003eb72(uVar7,&DAT_ffff86d0);
  DAT_ffffd100 = (float)FUN_00002068(uVar4,&DAT_0006b960);
  DAT_ffffd104 = (float)FUN_00002068(uVar4,&DAT_0006b870);
  DAT_ffffd108 = FUN_000020c4(uVar4,&DAT_0006b8c0);
  DAT_ffffd10a = FUN_000020c4(uVar4,&DAT_0006b8cc);
  cVar3 = DAT_ffffd006;
  DAT_ffffd0e8 = 0;
  DAT_ffffd0e9 = 0;
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd07b == '\x01')) {
    FUN_0003ebc0(&DAT_ffff86e8,0);
    FUN_0003ebc0(&DAT_ffff86ea,0);
  }
  else if (DAT_ffffd0e4 == '\x01') {
    if (((((DAT_ffffd108 < uVar1) && (fVar6 = (float)FUN_0003eb72(0,&DAT_ffff86e0), fVar5 < fVar6))
         && (cVar3 == '\x01')) && ((DAT_ffffd0d4 < DAT_ffffd100 && (DAT_ffffd104 < DAT_ffffd0d0))))
       || ((DAT_ffffd001 == '\x01' && (DAT_ffffd01c < DAT_ffffd020)))) {
      FUN_0003ebc0(&DAT_ffff86e8,1);
      DAT_ffffd0e8 = 1;
    }
    if (((DAT_ffffd10a < uVar1) && (DAT_ffffd0d8 <= fVar5)) && (cVar3 == '\x01')) {
      FUN_0003ebc0(&DAT_ffff86ea,1);
      DAT_ffffd0e9 = 1;
    }
  }
  FUN_000536e8();
  if (DAT_ffffd079 == '\x01') {
    DAT_ffffd0e5 = 0;
    DAT_ffffd0e6 = 0;
    uVar2 = 1;
  }
  else if ((DAT_ffffd075 == '\x01') || (uVar2 = (uint)DAT_ffffcfb4, uVar2 == 1)) {
    cVar3 = FUN_0003eaa4(&DAT_ffff86e8,0);
    if ((cVar3 == '\x01') && (cVar3 = FUN_000671a4(0x32), cVar3 == '\0')) {
      DAT_ffffd0e5 = 1;
      FUN_0003ebc0(&DAT_ffff86e8,0);
    }
    uVar2 = FUN_0003eaa4(&DAT_ffff86ea,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      uVar2 = FUN_000671a4(0x32);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        DAT_ffffd0e6 = 1;
        uVar2 = FUN_0003ebc0(&DAT_ffff86ea,0);
      }
    }
  }
  return uVar2;
}



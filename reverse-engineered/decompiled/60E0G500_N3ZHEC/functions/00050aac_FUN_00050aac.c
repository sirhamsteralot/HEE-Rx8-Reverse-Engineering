/* ROM address: 0x00050aac; body bytes: 368; decompiled */

uint FUN_00050aac(void)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar1 = DAT_ffffcfe6;
  uVar6 = 0;
  fVar5 = (float)FUN_0003eb72(0,&DAT_ffff86ac);
  uVar6 = FUN_0003eb72(uVar6,&DAT_ffff86a4);
  DAT_ffffd0ae = FUN_000020c4(uVar6,&DAT_0006b844);
  DAT_ffffd0b8 = FUN_000020c4(uVar6,&DAT_0006b850);
  bVar2 = DAT_ffffd07c;
  DAT_ffffd086 = 0;
  DAT_ffffd087 = 0;
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd07b == '\x01')) {
    DAT_ffffd080 = '\0';
  }
  else if (((uVar1 == DAT_ffffd0ae) && (fVar5 < DAT_ffffd054)) && (DAT_ffffd07c == 1)) {
    DAT_ffffd080 = '\x01';
  }
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd07b == '\x01')) {
    FUN_0003ebc0(&DAT_ffff86cc,0);
    uVar3 = FUN_0003ebc0(&DAT_ffff86ce,0);
  }
  else {
    if (((uVar1 == DAT_ffffd0b8) && (fVar5 < DAT_ffffd058)) && (DAT_ffffd080 == '\x01')) {
      if (DAT_ffffd07c != 1) {
        DAT_ffffd086 = 0;
        DAT_ffffd087 = 0;
        return (uint)DAT_ffffd07c;
      }
      cVar4 = FUN_0003eaa4(&DAT_ffff86c8,0);
      if (cVar4 == '\0') {
        FUN_0003ebc0(&DAT_ffff86cc,1);
        DAT_ffffd086 = 1;
      }
    }
    uVar3 = (uint)bVar2;
    if ((uVar3 == 1) &&
       ((((uVar1 <= DAT_ffffd0b8 && (DAT_ffffd0ae < uVar1)) && (DAT_ffffd068 <= fVar5)) ||
        (((uVar1 <= DAT_ffffd0ae && (DAT_ffffcfe4 < uVar1)) &&
         ((uVar3 = (uint)DAT_ffffd034, uVar3 == 0 && (DAT_ffffd064 <= fVar5)))))))) {
      uVar3 = FUN_0003ebc0(&DAT_ffff86ce,1);
      DAT_ffffd087 = 1;
    }
  }
  return uVar3;
}



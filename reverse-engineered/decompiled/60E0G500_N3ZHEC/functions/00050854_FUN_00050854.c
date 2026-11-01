/* ROM address: 0x00050854; body bytes: 352; decompiled */

uint FUN_00050854(void)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  float fVar4;
  undefined4 uVar5;
  
  uVar1 = DAT_ffffcfe6;
  uVar5 = 0;
  fVar4 = (float)FUN_0003eb72(0,&DAT_ffff86ac);
  uVar5 = FUN_0003eb72(uVar5,&DAT_ffff86a4);
  DAT_ffffd0ac = FUN_000020c4(uVar5,&DAT_0006b844);
  DAT_ffffd0b6 = FUN_000020c4(uVar5,&DAT_0006b850);
  bVar2 = DAT_ffffd07c;
  DAT_ffffd084 = 0;
  DAT_ffffd085 = 0;
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd07b == '\x01')) {
    DAT_ffffd07d = '\0';
  }
  else if (((uVar1 == DAT_ffffd0ac) && (fVar4 < DAT_ffffd05c)) && (DAT_ffffd07c == 1)) {
    DAT_ffffd07d = '\x01';
  }
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd07b == '\x01')) {
    FUN_0003ebc0(&DAT_ffff86c8,0);
    uVar3 = FUN_0003ebc0(&DAT_ffff86ca,0);
  }
  else {
    if (((uVar1 == DAT_ffffd0b6) && (fVar4 < DAT_ffffd060)) && (DAT_ffffd07d == '\x01')) {
      if (DAT_ffffd07c != 1) {
        DAT_ffffd084 = 0;
        DAT_ffffd085 = 0;
        return (uint)DAT_ffffd07c;
      }
      FUN_0003ebc0(&DAT_ffff86c8,1);
      DAT_ffffd084 = 1;
    }
    uVar3 = (uint)bVar2;
    if ((uVar3 == 1) &&
       ((((uVar1 <= DAT_ffffd0b6 && (DAT_ffffd0ac < uVar1)) && (DAT_ffffd070 <= fVar4)) ||
        (((uVar1 <= DAT_ffffd0ac && (DAT_ffffcfe4 < uVar1)) &&
         ((uVar3 = (uint)DAT_ffffd034, uVar3 == 0 && (DAT_ffffd06c <= fVar4)))))))) {
      uVar3 = FUN_0003ebc0(&DAT_ffff86ca,1);
      DAT_ffffd085 = 1;
    }
  }
  return uVar3;
}



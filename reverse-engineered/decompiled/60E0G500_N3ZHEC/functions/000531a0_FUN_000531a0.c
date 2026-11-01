/* ROM address: 0x000531a0; body bytes: 418; decompiled */

void FUN_000531a0(void)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  ushort uVar8;
  uint uVar6;
  char cVar9;
  char cVar10;
  uint uVar7;
  uint uVar11;
  float fVar12;
  
  uVar3 = DAT_ffffcfe6;
  uVar2 = DAT_ffffcfe4;
  fVar12 = DAT_ffffd030;
  uVar8 = FUN_00002460((int)(short)DAT_ffffcfe4,1);
  uVar6 = FUN_0003eaa4(&DAT_ffff8704,4);
  cVar9 = FUN_00002478(0x17,1);
  cVar10 = FUN_00011f34();
  cVar5 = DAT_ffffd201;
  cVar4 = DAT_ffffd002;
  uVar7 = FUN_0003eaa4(&DAT_ffff870a,0);
  cVar1 = DAT_ffffcfb4;
  if (cVar5 == '\x01') {
    uVar7 = 0;
  }
  uVar11 = 4;
  if (DAT_ffffd170 == DAT_ffffcfb4) {
    if (((uVar7 & 0xff) == 1) && (DAT_ffffd074 == '\x01')) {
      uVar11 = uVar6;
      if ((uVar6 & 0xff) < 4) {
        uVar11 = uVar6 + 1;
      }
    }
    else if (((((cVar4 != '\x01') || ((uVar3 != uVar8 || (0.0012 < fVar12)))) &&
              (DAT_ffffd155 != '\x01')) && ((cVar5 != '\x01' && (uVar11 = uVar6, cVar4 == '\x01'))))
            && ((((uVar3 == uVar8 && (0.0012 < fVar12)) ||
                 (((uVar2 < uVar3 && (DAT_ffffd034 == '\0')) && (DAT_ffffd16c == cVar9)))) &&
                ((uVar6 & 0xff) != 0)))) {
      uVar11 = uVar6 - 1;
    }
  }
  else if (DAT_ffffcfb4 == '\x01') {
    uVar11 = 1;
  }
  if (((DAT_ffffd171 == '\0') && (cVar10 == '\x01')) || (cVar5 == '\x01')) {
    uVar7 = 0;
  }
  else if ((((int)DAT_ffffcff1 & 0x80U) != 0) && ((uVar11 & 0xff) < (uint)DAT_ffffd16e)) {
    uVar7 = 1;
  }
  FUN_0003ebc0(&DAT_ffff8704,uVar11);
  FUN_0003ebc0(&DAT_ffff870a,uVar7);
  DAT_ffffd16e = (char)uVar11;
  DAT_ffffd171 = cVar10;
  DAT_ffffd170 = cVar1;
  return;
}



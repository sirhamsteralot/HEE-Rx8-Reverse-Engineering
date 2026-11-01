/* ROM address: 0x00017fc6; body bytes: 626; decompiled */

uint FUN_00017fc6(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  cVar7 = DAT_ffffa998;
  cVar6 = DAT_ffffa96c;
  cVar5 = DAT_ffffa96b;
  cVar4 = DAT_ffffa96a;
  cVar3 = DAT_ffffa969;
  bVar2 = DAT_ffffa968;
  if ((DAT_ffff9ecd & 2) == 0) {
    DAT_ffffa976 = '\0';
  }
  else {
    bVar1 = DAT_ffffa976 == '\0';
    DAT_ffffa976 = '\x01';
    if (bVar1) {
      DAT_ffffa987 = '\x01';
    }
  }
  if ((DAT_ffffa988 == '\x01') && (DAT_ffffa96c == '\0')) {
    DAT_ffffa989 = '\x01';
  }
  uVar10 = (uint)DAT_ffffa968;
  if (uVar10 == 0) {
    DAT_ffffa977 = '\0';
    DAT_ffffa978 = 0;
  }
  if (DAT_ffffa97b != 0) {
    DAT_ffffa97b = DAT_ffffa97b - 1;
  }
  uVar8 = (uint)DAT_ffffa97b;
  if (((DAT_ffffa97b == 1) && (uVar8 = uVar10, uVar10 == 1)) &&
     (uVar8 = (uint)DAT_ffffa982, uVar8 == 1)) {
    DAT_ffffa974 = 0;
    DAT_ffffa97f = 0;
    FUN_0003ebc0(&DAT_ffff807c,0);
    DAT_ffffa979 = 1;
    if (DAT_ffffa977 == '\x01') {
      DAT_ffffa977 = '\0';
      DAT_ffffa983 = 1;
      uVar8 = FUN_0003eaa4(&DAT_ffff8078,0);
      if ((uVar8 & 0xff) != 0) {
        FUN_0003ebc0(&DAT_ffff8078,uVar8 + 0xff);
      }
    }
    uVar8 = (uint)DAT_ffffa978;
    if (uVar8 == 1) {
      DAT_ffffa978 = 0;
    }
  }
  if (DAT_ffffa97b == 0) {
    DAT_ffffa974 = DAT_ffffa97f;
    if (cVar7 == '\x01') {
      FUN_000189d4();
    }
    else if (uVar10 == 1) {
      FUN_000185c8((int)(char)DAT_ffffa985);
    }
    else if ((cVar4 == '\x01') && (DAT_ffffcd06 == '\0')) {
      FUN_00018970();
    }
    else if (cVar5 == '\x01') {
      FUN_000189c4();
    }
    else if (cVar3 == '\x01') {
      FUN_00018756((int)DAT_ffffa984);
    }
    if ((cVar6 == '\x01') && (DAT_ffffa987 == '\x01')) {
      FUN_0003ebc0(&DAT_ffff807a,(int)(char)DAT_ffffa974);
    }
    bVar9 = FUN_0003eaa4(&DAT_ffff807a,0x37);
    if (DAT_ffffa989 == '\x01') {
      if ((bVar9 < 0x34) || ((0x3b < DAT_ffffa974 && (DAT_ffffa976 == '\0')))) {
        DAT_ffffa975 = FUN_00002478((int)DAT_ffffa975,1);
      }
      else if ((((0x33 < bVar9) && (0x3b < DAT_ffffa974)) && (DAT_ffffa976 == '\x01')) &&
              (DAT_ffffa975 != '\0')) {
        DAT_ffffa975 = DAT_ffffa975 + -1;
      }
      if (DAT_ffffa975 == '\0') {
        FUN_0003ebc0(&DAT_ffff8078,2);
      }
      if ((DAT_ffffa975 != '\0') && (DAT_ffffa975 != '\x04')) {
        DAT_ffffa979 = 0;
        DAT_ffffa982 = 0;
      }
    }
    DAT_ffffa983 = 0;
    DAT_ffffa987 = '\0';
    DAT_ffffa989 = '\0';
    DAT_ffffa985 = bVar2;
    DAT_ffffa984 = cVar3;
    uVar8 = (uint)cVar4;
    DAT_ffffa986 = cVar4;
  }
  DAT_ffffa988 = cVar6;
  return uVar8;
}



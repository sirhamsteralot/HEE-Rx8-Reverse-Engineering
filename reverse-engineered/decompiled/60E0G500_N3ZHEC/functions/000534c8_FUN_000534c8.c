/* ROM address: 0x000534c8; body bytes: 374; decompiled */

void FUN_000534c8(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8704,4);
  cVar9 = DAT_ffffcfb4;
  cVar3 = FUN_0003eaa4(&DAT_ffff86cc,0);
  cVar4 = FUN_0003eaa4(&DAT_ffff86ce,0);
  cVar5 = FUN_0003eaa4(&DAT_ffff86e8,0);
  cVar6 = FUN_0003eaa4(&DAT_ffff86ea,0);
  cVar7 = FUN_0003eaa4(&DAT_ffff86c8,0);
  cVar8 = FUN_0003eaa4(&DAT_ffff86ca,0);
  bVar1 = ((int)DAT_ffffcff1 & 0x80U) == 0;
  if (DAT_ffffd079 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8706,0);
    FUN_0003ebc0(&DAT_ffff8708,0);
  }
  else {
    if ((cVar2 == '\0') && (DAT_ffffd16f != '\0')) {
      if ((bVar1) && (cVar9 != '\x01')) {
        DAT_ffffd16f = cVar2;
        DAT_ffffd173 = cVar3;
        DAT_ffffd174 = cVar4;
        DAT_ffffd175 = cVar5;
        DAT_ffffd176 = cVar6;
        DAT_ffffd177 = cVar7;
        DAT_ffffd178 = cVar8;
        return;
      }
      FUN_0003ebc0(&DAT_ffff8706,1);
    }
    if ((((!bVar1) || (cVar9 == '\x01')) && (cVar9 = FUN_0003eaa4(&DAT_ffff8706,0), cVar9 == '\0'))
       && ((((((DAT_ffffd173 == '\0' && (cVar3 == '\x01')) ||
              ((DAT_ffffd174 == '\0' && (cVar4 == '\x01')))) ||
             ((DAT_ffffd175 == '\0' && (cVar5 == '\x01')))) ||
            ((DAT_ffffd176 == '\0' && (cVar6 == '\x01')))) ||
           (((DAT_ffffd177 == '\0' && (cVar7 == '\x01')) ||
            ((DAT_ffffd178 == '\0' && (cVar8 == '\x01')))))))) {
      FUN_0003ebc0(&DAT_ffff8708,1);
    }
  }
  DAT_ffffd16f = cVar2;
  DAT_ffffd173 = cVar3;
  DAT_ffffd174 = cVar4;
  DAT_ffffd175 = cVar5;
  DAT_ffffd176 = cVar6;
  DAT_ffffd177 = cVar7;
  DAT_ffffd178 = cVar8;
  return;
}



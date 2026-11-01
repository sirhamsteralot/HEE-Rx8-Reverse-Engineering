/* ROM address: 0x000502f8; body bytes: 304; decompiled */

uint FUN_000502f8(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar2 = FUN_0003eaa4(&DAT_ffff86c4,0);
  cVar1 = DAT_ffffd07c;
  if ((((((((int)DAT_ffffcff1 & 0x80U) != 0) && (DAT_ffffd04a == '\x01')) && (DAT_ffffd04c == '\0'))
       && ((DAT_ffffcd06 == '\0' && (DAT_ffffa96a == '\0')))) && (DAT_ffffbe0c == '\0')) ||
     (uVar3 = (uint)DAT_ffffcfb4, uVar3 == 1)) {
    uVar3 = FUN_0003eaa4(&DAT_ffff86cc,0);
    uVar3 = uVar3 & 0xff;
    if (uVar3 == 0) {
      uVar3 = FUN_0003eaa4(&DAT_ffff86ce,0);
      uVar3 = uVar3 & 0xff;
      if (uVar3 == 0) {
        uVar3 = FUN_0003eaa4(&DAT_ffff86c8,0);
        uVar3 = uVar3 & 0xff;
        if ((uVar3 == 0) && (DAT_ffffcfed != '\0')) {
          if (((uVar2 & 0xff) == 1) || ((uVar2 & 0xff) == 3)) {
            uVar3 = FUN_0003eaa4(&DAT_ffff86c6,0);
            uVar3 = uVar3 & 0xff;
            if ((uVar2 & 0xff) == uVar3) goto LAB_000503be;
          }
          else {
LAB_000503be:
            uVar3 = (uint)DAT_ffffd0e4;
            if (uVar3 != 1) goto LAB_00050400;
          }
          DAT_ffffd07c = 1;
          goto LAB_00050402;
        }
      }
    }
  }
LAB_00050400:
  DAT_ffffd07c = 0;
LAB_00050402:
  if ((cVar1 == '\0') && (uVar3 = (uint)DAT_ffffd07c, uVar3 == 1)) {
    uVar4 = 0;
    DAT_ffffd07e = 0;
    DAT_ffffd07f = 0;
    DAT_ffffd081 = 0;
    DAT_ffffd082 = 0;
    FUN_0003ec20(0,&DAT_ffff86ac);
    FUN_0003ec20(uVar4,&DAT_ffff86b4);
    uVar3 = FUN_0003ec20(uVar4,&DAT_ffff86bc);
  }
  return uVar3;
}



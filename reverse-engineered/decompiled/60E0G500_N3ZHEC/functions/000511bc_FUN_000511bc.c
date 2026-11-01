/* ROM address: 0x000511bc; body bytes: 278; decompiled */

uint FUN_000511bc(void)

{
  char cVar1;
  char cVar3;
  uint uVar2;
  undefined4 uVar4;
  
  cVar1 = DAT_ffffd0e4;
  if (((((((DAT_ffffd04a == '\x01') && (((int)DAT_ffffcff1 & 0x80U) != 0)) && (DAT_ffffd04c == '\0')
         ) && ((DAT_ffffcd06 == '\0' && (DAT_ffffa96a == '\0')))) &&
       ((DAT_ffffbe0c == '\0' &&
        ((cVar3 = FUN_0003eaa4(&DAT_ffff870c,0), cVar3 == '\x01' ||
         (cVar3 = FUN_00060194(0x31,2), cVar3 == '\x01')))))) && (0x249 < DAT_ffffd048)) ||
     (uVar2 = (uint)DAT_ffffcfb4, uVar2 == 1)) {
    uVar2 = FUN_0003eaa4(&DAT_ffff86e8,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = FUN_0003eaa4(&DAT_ffff86ea,0);
      uVar2 = uVar2 & 0xff;
      if ((uVar2 == 0) && (DAT_ffffcfed != '\0')) {
        uVar2 = 1;
        DAT_ffffd0e4 = 1;
        goto LAB_000512b2;
      }
    }
  }
  DAT_ffffd0e4 = 0;
LAB_000512b2:
  if ((cVar1 == '\0') && (uVar2 = (uint)DAT_ffffd0e4, uVar2 == 1)) {
    uVar4 = 0;
    DAT_ffffd0dc = 0;
    DAT_ffffd0de = 0;
    DAT_ffffd0e0 = 0;
    DAT_ffffd0e2 = 0;
    DAT_ffffd0d0 = 0;
    FUN_0003ec20(0,&DAT_ffff86d0);
    FUN_0003ec20(uVar4,&DAT_ffff86d8);
    uVar2 = FUN_0003ec20(uVar4,&DAT_ffff86e0);
  }
  return uVar2;
}



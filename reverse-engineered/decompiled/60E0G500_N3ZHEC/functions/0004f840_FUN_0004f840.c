/* ROM address: 0x0004f840; body bytes: 310; decompiled */

char FUN_0004f840(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  
  cVar4 = DAT_ffffd004;
  cVar3 = DAT_ffffd003;
  cVar2 = DAT_ffffd002;
  cVar1 = DAT_ffffd001;
  cVar6 = -((((int)(char)DAT_ffffcff1 & 0x80U) == 0) + -1);
  if (((cVar6 == '\x01') &&
      ((((((DAT_ffffd001 == '\x01' || (DAT_ffffd002 == '\0')) ||
          (cVar5 = FUN_0003eaa4(&DAT_ffff86cc,0), cVar5 == '\x01')) ||
         ((cVar5 = FUN_0003eaa4(&DAT_ffff86c8,0), cVar5 == '\x01' ||
          ((DAT_ffffd011 == '\0' && (cVar4 == '\x01')))))) ||
        ((DAT_ffffd012 == '\0' && (cVar3 == '\x01')))) ||
       (cVar5 = FUN_0003eaa4(&DAT_ffff870a,0), cVar5 == '\x01')))) &&
     (((DAT_ffffd04c == '\0' && (DAT_ffffcd06 == '\0')) &&
      ((DAT_ffffa96a == '\0' && (DAT_ffffbe0c == '\0')))))) {
    DAT_ffffd000 = 0;
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
    if (((((DAT_ffffcff1 & 0x40) != 0) || (cVar5 = '\x01', (DAT_ffffcff1 & 0x20) != 0)) ||
        (cVar5 = '\x01', DAT_ffffd005 == '\x01')) ||
       (((cVar5 = cVar6, cVar6 == '\x01' && (cVar1 == '\0')) && (cVar5 = cVar2, cVar2 == '\x01'))))
    {
      DAT_ffffd000 = 1;
    }
  }
  DAT_ffffd011 = cVar4;
  DAT_ffffd012 = cVar3;
  return cVar5;
}



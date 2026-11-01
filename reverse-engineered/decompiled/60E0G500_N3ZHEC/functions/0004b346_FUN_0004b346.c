/* ROM address: 0x0004b346; body bytes: 152; decompiled */

char FUN_0004b346(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar4 = DAT_ffffd201;
  cVar2 = DAT_ffffce07;
  sVar1 = DAT_ffffce02;
  if ((DAT_ffffce07 == '\x01') ||
     (((DAT_ffffce0c != 0 && (DAT_ffffce02 == 0)) || (DAT_ffffd201 == '\x01')))) {
    DAT_ffffce04 = 0;
  }
  else if (DAT_ffff9fa2 == '\x01') {
    DAT_ffffce04 = FUN_00002478((int)(char)DAT_ffffce04,1);
  }
  cVar3 = '\x01';
  if ((cVar2 == '\x01') || (cVar3 = cVar4, cVar4 == '\x01')) {
    DAT_ffffce00 = 0;
    cVar4 = cVar3;
  }
  else if (0x48 < DAT_ffffce04) {
    DAT_ffffce00 = 1;
  }
  DAT_ffffce0c = sVar1;
  return cVar4;
}



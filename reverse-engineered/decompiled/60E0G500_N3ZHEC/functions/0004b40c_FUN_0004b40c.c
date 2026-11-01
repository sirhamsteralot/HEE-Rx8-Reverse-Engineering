/* ROM address: 0x0004b40c; body bytes: 150; decompiled */

char FUN_0004b40c(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar4 = DAT_ffffd201;
  cVar2 = DAT_ffffce07;
  sVar1 = DAT_ffffce02;
  if ((DAT_ffffce07 == '\x01') ||
     (((DAT_ffffce0e != 0 && (DAT_ffffce02 == 0)) || (DAT_ffffd201 == '\x01')))) {
    DAT_ffffce05 = 0;
  }
  else if (DAT_ffffce11 == '\0') {
    DAT_ffffce05 = FUN_00002478((int)(char)DAT_ffffce05,1);
  }
  cVar3 = '\x01';
  if ((cVar2 == '\x01') || (cVar3 = cVar4, cVar4 == '\x01')) {
    DAT_ffffce01 = 0;
    cVar4 = cVar3;
  }
  else if (0xc < DAT_ffffce05) {
    DAT_ffffce01 = 1;
  }
  DAT_ffffce0e = sVar1;
  return cVar4;
}



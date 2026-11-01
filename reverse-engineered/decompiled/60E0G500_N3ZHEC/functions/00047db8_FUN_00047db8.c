/* ROM address: 0x00047db8; body bytes: 198; decompiled */

char FUN_00047db8(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  
  if ((DAT_ffffb570 == '\x01') || (DAT_ffffb573 == '\x01')) {
    DAT_ffffccd3 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffccd3 = 0;
    bVar1 = false;
  }
  if ((DAT_ffffb575 == '\x01') || (DAT_ffffb577 == '\x01')) {
    DAT_ffffccd4 = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffccd4 = 0;
    bVar2 = false;
  }
  if (((bVar1) && (bVar2)) || (DAT_ffffb57a == '\x01')) {
    DAT_ffffccd5 = 1;
  }
  else {
    DAT_ffffccd5 = 0;
  }
  if ((bVar1) || (DAT_ffffb57a == '\x01')) {
    DAT_ffffccd8 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffccd8 = 0;
    bVar1 = false;
  }
  if ((bVar2) || (DAT_ffffb57a == '\x01')) {
    DAT_ffffccd9 = '\x01';
  }
  else {
    DAT_ffffccd9 = '\0';
  }
  cVar3 = '\x01';
  if ((bVar1) || (cVar3 = DAT_ffffccd9, DAT_ffffccd9 == '\x01')) {
    DAT_ffffccda = 1;
  }
  else {
    DAT_ffffccda = 0;
  }
  return cVar3;
}



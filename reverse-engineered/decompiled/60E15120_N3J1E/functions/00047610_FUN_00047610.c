/* ROM address: 0x00047610; body bytes: 198; decompiled */

char FUN_00047610(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  
  if ((DAT_ffffb500 == '\x01') || (DAT_ffffb503 == '\x01')) {
    DAT_ffffcc93 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffcc93 = 0;
    bVar1 = false;
  }
  if ((DAT_ffffb505 == '\x01') || (DAT_ffffb507 == '\x01')) {
    DAT_ffffcc94 = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffcc94 = 0;
    bVar2 = false;
  }
  if (((bVar1) && (bVar2)) || (DAT_ffffb50a == '\x01')) {
    DAT_ffffcc95 = 1;
  }
  else {
    DAT_ffffcc95 = 0;
  }
  if ((bVar1) || (DAT_ffffb50a == '\x01')) {
    DAT_ffffcc98 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffcc98 = 0;
    bVar1 = false;
  }
  if ((bVar2) || (DAT_ffffb50a == '\x01')) {
    DAT_ffffcc99 = '\x01';
  }
  else {
    DAT_ffffcc99 = '\0';
  }
  cVar3 = '\x01';
  if ((bVar1) || (cVar3 = DAT_ffffcc99, DAT_ffffcc99 == '\x01')) {
    DAT_ffffcc9a = 1;
  }
  else {
    DAT_ffffcc9a = 0;
  }
  return cVar3;
}



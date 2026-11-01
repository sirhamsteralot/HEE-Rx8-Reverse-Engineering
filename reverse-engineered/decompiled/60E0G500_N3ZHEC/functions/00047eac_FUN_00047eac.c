/* ROM address: 0x00047eac; body bytes: 236; decompiled */

char FUN_00047eac(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = FUN_0003eaa4(&DAT_ffff8754,0);
  cVar4 = FUN_0003eaa4(&DAT_ffff8758,0);
  if ((cVar4 == '\x01') || (cVar4 = FUN_0003eaa4(&DAT_ffff875a,0), cVar4 == '\x01')) {
    DAT_ffffccd6 = '\x01';
  }
  else {
    DAT_ffffccd6 = '\0';
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff875c,0);
  if ((cVar4 == '\x01') || (cVar4 = FUN_0003eaa4(&DAT_ffff875e,0), cVar4 == '\x01')) {
    DAT_ffffccd7 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffccd7 = 0;
    bVar1 = false;
  }
  if (((DAT_ffffccd6 == '\x01') && (bVar1)) || (cVar3 == '\x01')) {
    DAT_ffffccde = 1;
  }
  else {
    DAT_ffffccde = 0;
  }
  if ((DAT_ffffccd6 == '\x01') || (cVar3 == '\x01')) {
    DAT_ffffccdb = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffccdb = 0;
    bVar2 = false;
  }
  if ((bVar1) || (cVar3 == '\x01')) {
    DAT_ffffccdc = '\x01';
  }
  else {
    DAT_ffffccdc = '\0';
  }
  cVar3 = '\x01';
  if ((bVar2) || (cVar3 = DAT_ffffccdc, DAT_ffffccdc == '\x01')) {
    DAT_ffffccdd = 1;
  }
  else {
    DAT_ffffccdd = 0;
  }
  return cVar3;
}



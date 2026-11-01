/* ROM address: 0x0004fabe; body bytes: 168; decompiled */

void FUN_0004fabe(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  cVar4 = DAT_ffffd12e;
  cVar3 = DAT_ffffd0e4;
  cVar2 = DAT_ffffd07c;
  cVar1 = DAT_ffffcfc1;
  uVar5 = FUN_00003920(0x10);
  if (DAT_ffffcffa == '\0') {
    DAT_ffffd01c = 0;
  }
  if (((((DAT_ffffd03f == '\0') && (cVar2 == '\x01')) ||
       ((DAT_ffffd040 == '\0' && (cVar3 == '\x01')))) ||
      ((DAT_ffffd03e == '\0' && (cVar4 == '\x01')))) || ((DAT_ffffd03c == '\0' && (cVar1 != '\0'))))
  {
    DAT_ffffd024 = 0x3d1ba5e3;
  }
  FUN_00003934(uVar5);
  DAT_ffffd03c = cVar1;
  DAT_ffffd03f = cVar2;
  DAT_ffffd040 = cVar3;
  DAT_ffffd03e = cVar4;
  return;
}



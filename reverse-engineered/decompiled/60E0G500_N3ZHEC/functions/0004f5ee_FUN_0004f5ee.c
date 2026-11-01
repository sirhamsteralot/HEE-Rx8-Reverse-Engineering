/* ROM address: 0x0004f5ee; body bytes: 278; decompiled */

void FUN_0004f5ee(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffcff7;
  cVar1 = DAT_ffffcff6;
  if (DAT_ffffcff6 == '\x01') {
    if ((DAT_ffffd00f == '\0') || (DAT_ffffd00a == '\0')) {
      DAT_ffffcfe9 = '\0';
    }
    else {
      DAT_ffffcfe9 = FUN_00002478((int)DAT_ffffcfe9,1);
    }
    if (DAT_ffffd00f == '\0') {
      DAT_ffffcfe8 = '\0';
    }
    else if ((DAT_ffffd00a == '\0') && (DAT_ffffcfe9 == '\0')) {
      DAT_ffffcfe8 = FUN_00002478((int)DAT_ffffcfe8,1);
    }
  }
  if (cVar2 == '\x01') {
    if ((DAT_ffffd010 == '\0') || (DAT_ffffd00b == '\0')) {
      DAT_ffffcfeb = '\0';
    }
    else {
      DAT_ffffcfeb = FUN_00002478((int)DAT_ffffcfeb,1);
    }
    if (DAT_ffffd010 == '\0') {
      DAT_ffffcfea = '\0';
    }
    else if ((DAT_ffffd00b == '\0') && (DAT_ffffcfeb == '\0')) {
      DAT_ffffcfea = FUN_00002478((int)DAT_ffffcfea,1);
    }
  }
  DAT_ffffd00f = cVar1;
  DAT_ffffd010 = cVar2;
  DAT_ffffd00a = DAT_ffffcfe9;
  DAT_ffffd00b = DAT_ffffcfeb;
  return;
}



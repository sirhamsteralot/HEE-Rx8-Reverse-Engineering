/* ROM address: 0x000307f4; body bytes: 172; decompiled */

char FUN_000307f4(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffaae0;
  cVar1 = DAT_ffffa42c;
  if (DAT_ffffaae0 == '\x01') {
    DAT_ffffbe46 = FUN_00002460((int)(short)DAT_ffffbe46,1);
  }
  else {
    DAT_ffffbe46 = 0;
  }
  if (cVar1 == '\x01') {
    DAT_ffffbe4a = FUN_00002460((int)DAT_ffffbe4a,1);
  }
  else {
    DAT_ffffbe4a = 0;
    DAT_ffffbe4c = '\0';
  }
  DAT_ffffbe48 = FUN_00002460((int)(short)DAT_ffffbe48,1);
  if (((DAT_ffffbe46 < 0x1f) ||
      (((cVar1 == '\x01' && (cVar1 = DAT_ffffbe4c, DAT_ffffbe4c == '\x01')) || (DAT_ffffbe48 < 0x3f)
       ))) && (cVar1 = cVar2, cVar2 == '\x01')) {
    DAT_ffffbe44 = 1;
  }
  else {
    cVar2 = cVar1;
    DAT_ffffbe44 = 0;
  }
  return cVar2;
}



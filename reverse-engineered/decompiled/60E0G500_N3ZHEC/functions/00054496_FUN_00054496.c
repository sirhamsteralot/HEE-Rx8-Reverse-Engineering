/* ROM address: 0x00054496; body bytes: 86; decompiled */

char FUN_00054496(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = DAT_ffffd1dc;
  cVar2 = FUN_00055a50();
  if (((cVar2 == '\0') || (bVar1 < 0x88)) || (0x87 < bVar1)) {
    cVar2 = '\0';
    DAT_ffffd1e0 = 0;
  }
  else {
    DAT_ffffd1e0 = 1;
  }
  return cVar2;
}



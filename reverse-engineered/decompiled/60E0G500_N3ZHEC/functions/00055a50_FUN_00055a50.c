/* ROM address: 0x00055a50; body bytes: 106; decompiled */

byte FUN_00055a50(void)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff8fec,0);
  bVar2 = cVar1 == '\0';
  cVar1 = FUN_0003eaa4(&DAT_ffff8ff8,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 4;
  }
  cVar1 = FUN_0003eaa4(&DAT_ffff8fe8,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 8;
  }
  cVar1 = FUN_0003eaa4(&DAT_ffff8ff0,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 0x20;
  }
  cVar1 = FUN_0003eaa4(&DAT_ffff9006,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 0x40;
  }
  return bVar2 & DAT_ffffd2c5;
}



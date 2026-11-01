/* ROM address: 0x00044722; body bytes: 88; decompiled */

byte FUN_00044722(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffbb4d >> 4;
  bVar1 = DAT_ffffbb4e >> 4;
  if ((((bVar2 == 3) && (bVar1 == 3)) || ((bVar2 == 4 && (bVar2 = bVar1, bVar1 == 4)))) &&
     (bVar2 = bVar1, DAT_ffffcab3 == '\0')) {
    bVar2 = 1;
    DAT_ffffcabc = 1;
  }
  else {
    DAT_ffffcabc = 0;
  }
  return bVar2;
}



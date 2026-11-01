/* ROM address: 0x0002a5fe; body bytes: 78; decompiled */

byte FUN_0002a5fe(void)

{
  byte bVar1;
  
  bVar1 = 1;
  if ((((DAT_ffffc600 == '\x01') || (bVar1 = 1, DAT_ffffc656 == '\x01')) ||
      (bVar1 = 1, DAT_ffffc64b == '\x01')) ||
     ((bVar1 = 1, DAT_ffffc647 == '\x01' || (bVar1 = DAT_ffffccd1, 2 < DAT_ffffccd1)))) {
    DAT_ffffbb8c = 1;
  }
  else {
    DAT_ffffbb8c = 0;
  }
  return bVar1;
}



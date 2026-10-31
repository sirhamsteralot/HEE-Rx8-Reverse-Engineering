/* ROM address: 0x00029a6e; body bytes: 78; decompiled */

byte FUN_00029a6e(void)

{
  byte bVar1;
  
  bVar1 = 1;
  if ((((DAT_ffffc590 == '\x01') || (bVar1 = 1, DAT_ffffc5e6 == '\x01')) ||
      (bVar1 = 1, DAT_ffffc5db == '\x01')) ||
     ((bVar1 = 1, DAT_ffffc5d7 == '\x01' || (bVar1 = DAT_ffffcc91, 2 < DAT_ffffcc91)))) {
    DAT_ffffbb24 = 1;
  }
  else {
    DAT_ffffbb24 = 0;
  }
  return bVar1;
}



/* ROM address: 0x0005aa98; body bytes: 122; decompiled */

byte FUN_0005aa98(void)

{
  byte bVar1;
  
  if ((DAT_ffffc068 == 0xff) &&
     ((bVar1 = DAT_ffffc069, 0x7f < DAT_ffffc069 || (bVar1 = DAT_ffffc06a, 0x7f < DAT_ffffc06a)))) {
    DAT_ffffd2c3 = 0xff;
  }
  else {
    bVar1 = 0xff;
    if ((DAT_ffffc068 == 0xff) && ((DAT_ffffc069 < 0x80 || (DAT_ffffc06a < 0x80)))) {
      DAT_ffffd2c3 = 0;
    }
    else {
      DAT_ffffd2c3 = (undefined1)((uint)DAT_ffffc068 * 0xff >> 8);
    }
  }
  return bVar1;
}



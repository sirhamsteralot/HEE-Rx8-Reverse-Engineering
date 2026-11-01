/* ROM address: 0x0005a2f4; body bytes: 122; decompiled */

byte FUN_0005a2f4(void)

{
  byte bVar1;
  
  if ((DAT_ffffc000 == 0xff) &&
     ((bVar1 = DAT_ffffc001, 0x7f < DAT_ffffc001 || (bVar1 = DAT_ffffc002, 0x7f < DAT_ffffc002)))) {
    inferred_ram_d287_ffffd287_ffffd287 = 0xff;
  }
  else {
    bVar1 = 0xff;
    if ((DAT_ffffc000 == 0xff) && ((DAT_ffffc001 < 0x80 || (DAT_ffffc002 < 0x80)))) {
      inferred_ram_d287_ffffd287_ffffd287 = 0;
    }
    else {
      inferred_ram_d287_ffffd287_ffffd287 = (undefined1)((uint)DAT_ffffc000 * 0xff >> 8);
    }
  }
  return bVar1;
}



/* ROM address: 0x0002c2e4; body bytes: 52; decompiled */

byte FUN_0002c2e4(void)

{
  byte bVar1;
  
  bVar1 = DAT_ffffbc5e & 0x40;
  if ((bVar1 == 0x40) && (bVar1 = DAT_ffffa428, DAT_ffffa428 == 1)) {
    DAT_ffffbc34 = 1;
  }
  else {
    DAT_ffffbc34 = 0;
  }
  return bVar1;
}



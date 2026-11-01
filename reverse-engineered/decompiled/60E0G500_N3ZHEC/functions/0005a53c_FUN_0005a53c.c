/* ROM address: 0x0005a53c; body bytes: 214; decompiled */

byte FUN_0005a53c(void)

{
  if (DAT_ffffd298 == '\0') {
    DAT_ffffd2a4 = 0;
  }
  else if ((DAT_ffffd28e == 0x10) && (0x5d < DAT_ffffd288)) {
    DAT_ffffd2a4 = 1;
  }
  DAT_ffffd2a5 = DAT_ffffd28e != 0;
  DAT_ffffd2a6 = DAT_ffffd28e != 0;
  if (((DAT_ffffd2a1 == '\x01') && (0xf < DAT_ffffd28e)) && (DAT_ffffd28e < 0x21)) {
    DAT_ffffd2a7 = 1;
  }
  else {
    DAT_ffffd2a7 = 0;
  }
  if ((DAT_ffffd28e < 0x30) || (0x40 < DAT_ffffd28e)) {
    DAT_ffffd2a8 = 0;
  }
  else {
    DAT_ffffd2a8 = 1;
  }
  if ((DAT_ffffd28e < 0x60) || (0x70 < DAT_ffffd28d)) {
    DAT_ffffd2a9 = 0;
  }
  else {
    DAT_ffffd2a9 = 1;
  }
  DAT_ffffd2aa = DAT_ffffd28e == 0x60;
  return DAT_ffffd28e;
}



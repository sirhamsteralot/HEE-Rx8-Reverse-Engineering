/* ROM address: 0x00059d98; body bytes: 214; decompiled */

byte FUN_00059d98(void)

{
  if (DAT_ffffd25c == '\0') {
    DAT_ffffd268 = 0;
  }
  else if ((DAT_ffffd252 == 0x10) && (0x5d < DAT_ffffd24c)) {
    DAT_ffffd268 = 1;
  }
  DAT_ffffd269 = DAT_ffffd252 != 0;
  DAT_ffffd26a = DAT_ffffd252 != 0;
  if (((DAT_ffffd265 == '\x01') && (0xf < DAT_ffffd252)) && (DAT_ffffd252 < 0x21)) {
    DAT_ffffd26b = 1;
  }
  else {
    DAT_ffffd26b = 0;
  }
  if ((DAT_ffffd252 < 0x30) || (0x40 < DAT_ffffd252)) {
    DAT_ffffd26c = 0;
  }
  else {
    DAT_ffffd26c = 1;
  }
  if ((DAT_ffffd252 < 0x60) || (0x70 < DAT_ffffd251)) {
    DAT_ffffd26d = 0;
  }
  else {
    DAT_ffffd26d = 1;
  }
  DAT_ffffd26e = DAT_ffffd252 == 0x60;
  return DAT_ffffd252;
}



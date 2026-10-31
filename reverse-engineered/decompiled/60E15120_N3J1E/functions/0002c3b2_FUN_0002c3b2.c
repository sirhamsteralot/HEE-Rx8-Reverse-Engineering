/* ROM address: 0x0002c3b2; body bytes: 356; decompiled */

uint FUN_0002c3b2(void)

{
  uint uVar1;
  
  if (DAT_ffffb53a == '\x01') {
    DAT_ffffbc3d = 0;
  }
  else if ((DAT_ffffbc3c == 1) && (0xb < DAT_ffffbc4a)) {
    DAT_ffffbc3d = 1;
  }
  else if ((DAT_ffffbc3c == 2) && (0xb < DAT_ffffbc4c)) {
    DAT_ffffbc3d = 2;
  }
  else if ((DAT_ffffbc3c == 3) && (0xb < DAT_ffffbc4e)) {
    DAT_ffffbc3d = 3;
  }
  else if ((DAT_ffffbc3c == 4) && (0xb < DAT_ffffbc50)) {
    DAT_ffffbc3d = 4;
  }
  else if ((DAT_ffffbc3c == 5) && (0xb < DAT_ffffbc52)) {
    DAT_ffffbc3d = 5;
  }
  else if ((DAT_ffffbc3c == 6) && (0xb < DAT_ffffbc54)) {
    DAT_ffffbc3d = 6;
  }
  if (DAT_ffffbc3c == 1) {
    DAT_ffffbc4a = rx8_add_u16_saturate((int)(short)DAT_ffffbc4a,1);
  }
  else {
    DAT_ffffbc4a = 0;
  }
  if (DAT_ffffbc3c == 2) {
    DAT_ffffbc4c = rx8_add_u16_saturate((int)(short)DAT_ffffbc4c,1);
  }
  else {
    DAT_ffffbc4c = 0;
  }
  if (DAT_ffffbc3c == 3) {
    DAT_ffffbc4e = rx8_add_u16_saturate((int)(short)DAT_ffffbc4e,1);
  }
  else {
    DAT_ffffbc4e = 0;
  }
  if (DAT_ffffbc3c == 4) {
    DAT_ffffbc50 = rx8_add_u16_saturate((int)(short)DAT_ffffbc50,1);
  }
  else {
    DAT_ffffbc50 = 0;
  }
  if (DAT_ffffbc3c == 5) {
    DAT_ffffbc52 = rx8_add_u16_saturate((int)(short)DAT_ffffbc52,1);
  }
  else {
    DAT_ffffbc52 = 0;
  }
  uVar1 = (uint)DAT_ffffbc3c;
  if (uVar1 == 6) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbc54,1);
    DAT_ffffbc54 = (ushort)uVar1;
  }
  else {
    DAT_ffffbc54 = 0;
  }
  return uVar1;
}



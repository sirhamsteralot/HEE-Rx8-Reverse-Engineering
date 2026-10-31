/* ROM address: 0x0002c15a; body bytes: 382; decompiled */

uint FUN_0002c15a(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  if (DAT_ffffb534 == 1) {
    if (vehicle_speed_ffffbbb4 < 0.0) {
      if (vehicle_speed_ffffbbb4 < -2.0) {
        DAT_ffffbc56 = '\0';
      }
    }
    else {
      DAT_ffffbc56 = '\x01';
    }
    if (((DAT_ffffbc3e == '\x01') && (1 < DAT_ffffbc44)) || (DAT_ffffbc56 == '\0')) {
      DAT_ffffbc41 = 1;
    }
    else if ((DAT_ffffbc3e == '\0') && (DAT_ffffbc56 == '\x01')) {
      DAT_ffffbc41 = 0;
    }
    if (DAT_ffffbc3f == '\x01') {
      if (1 < DAT_ffffbc46) {
        DAT_ffffbc42 = 1;
      }
    }
    else {
      DAT_ffffbc42 = 0;
    }
    if (DAT_ffffbc40 == 1) {
      if (1 < DAT_ffffbc48) {
        DAT_ffffbc43 = 1;
      }
    }
    else {
      DAT_ffffbc43 = 0;
    }
    if (DAT_ffffbc3e == '\x01') {
      DAT_ffffbc44 = rx8_add_u16_saturate((int)(short)DAT_ffffbc44,1);
    }
    else {
      DAT_ffffbc44 = 0;
    }
    if (DAT_ffffbc3f == '\x01') {
      DAT_ffffbc46 = rx8_add_u16_saturate((int)(short)DAT_ffffbc46,1);
    }
    else {
      DAT_ffffbc46 = 0;
    }
    if (DAT_ffffbc40 == 1) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbc48,1);
      DAT_ffffbc48 = (ushort)uVar1;
    }
    else {
      DAT_ffffbc48 = 0;
      uVar1 = (uint)DAT_ffffbc40;
    }
  }
  else {
    DAT_ffffbc41 = 0;
    uVar2 = (uint)DAT_ffffbaed;
    DAT_ffffbc42 = 0;
    uVar1 = (uint)DAT_ffffb534;
    DAT_ffffbc43 = uVar3;
    if (uVar2 != 0) {
      uVar1 = uVar2;
      if (uVar2 == 1) {
        DAT_ffffbc41 = 1;
      }
      else if ((uVar2 == 2) || (uVar2 == 3)) {
        DAT_ffffbc42 = 1;
      }
      else if (uVar2 == 4) {
        DAT_ffffbc43 = 1;
      }
      else if (((uVar2 != 5) && (uVar2 != 6)) && (uVar2 == 7)) {
        DAT_ffffbc41 = 1;
      }
    }
  }
  return uVar1;
}



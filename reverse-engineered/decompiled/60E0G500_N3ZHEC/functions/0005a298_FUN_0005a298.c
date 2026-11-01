/* ROM address: 0x0005a298; body bytes: 554; decompiled */

uint FUN_0005a298(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = DAT_ffffd28e;
  uVar2 = FUN_00003920(0x10);
  if ((((DAT_ffffd29b == '\0') || (DAT_ffffd298 == '\0')) || (DAT_ffffd294 == '\x01')) ||
     ((DAT_ffffd28e == 0x80 || (0xafc < DAT_ffffd286)))) {
    DAT_ffffd28e = 0;
  }
  else if ((DAT_ffffd28e == 0) && (DAT_ffffd291 == '\x01')) {
    DAT_ffffd28e = 0x10;
  }
  else if ((DAT_ffffd28e != 0x10) || (DAT_ffffb5b8 <= 900.0)) {
    if ((DAT_ffffd28e == 0x20) && ((DAT_ffffd2a1 == '\0' || (DAT_ffffcfc3 == '\x01')))) {
      DAT_ffffd28e = 0x30;
    }
    else if ((DAT_ffffd28e == 0x30) && (1 < DAT_ffffd288)) {
      DAT_ffffd28e = 0x40;
    }
    else if ((DAT_ffffd28e == 0x40) && (0x1d5 < DAT_ffffd288)) {
      DAT_ffffd28e = 0x50;
    }
    else if ((DAT_ffffd28e == 0x50) && (1 < DAT_ffffd288)) {
      DAT_ffffd28e = 0x60;
    }
    else if ((DAT_ffffd28e == 0x60) && (0xdb < DAT_ffffd288)) {
      DAT_ffffd28e = 0x70;
    }
    else if (((DAT_ffffd28e == 0x70) && (1 < DAT_ffffd288)) ||
            ((DAT_ffffd28e == 0x10 && (0x5d < DAT_ffffd288)))) {
      DAT_ffffd28e = 0x80;
    }
  }
  else {
    DAT_ffffd28e = 0x20;
  }
  if (DAT_ffffd28e == 0) {
    DAT_ffffd2a2 = 0;
  }
  DAT_ffffd291 = 0;
  DAT_ffffd294 = 0;
  uVar3 = FUN_00003934(uVar2);
  uVar4 = (uint)DAT_ffffd28e;
  if ((((((uVar4 == 0) || ((uVar3 = uVar4, bVar1 == 0 && (uVar4 == 0x10)))) ||
        ((bVar1 == 0x10 && (uVar4 == 0x20)))) ||
       (((bVar1 == 0x20 && (uVar4 == 0x30)) || ((bVar1 == 0x30 && (uVar4 == 0x40)))))) ||
      (((bVar1 == 0x40 && (uVar4 == 0x50)) || ((bVar1 == 0x50 && (uVar4 == 0x60)))))) ||
     ((uVar3 = (uint)bVar1, bVar1 == 0x60 && (uVar3 = uVar4, uVar4 == 0x70)))) {
    DAT_ffffd288 = 0;
  }
  else if (DAT_ffffd288 != 0xffff) {
    DAT_ffffd288 = DAT_ffffd288 + 1;
  }
  if (DAT_ffffd28e == 0) {
    DAT_ffffd286 = 0;
  }
  else if (DAT_ffffd286 != 0xffff) {
    DAT_ffffd286 = DAT_ffffd286 + 1;
  }
  return uVar3;
}



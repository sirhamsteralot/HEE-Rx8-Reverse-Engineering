/* ROM address: 0x000433c2; body bytes: 190; decompiled */

uint FUN_000433c2(void)

{
  uint uVar1;
  
  if ((DAT_ffffca4b == '\x01') || (DAT_ffffca49 == '\x01')) {
    uVar1 = 1;
    DAT_ffffca45 = 0;
  }
  else {
    uVar1 = (uint)DAT_ffffca44;
    if (((uVar1 != 1) || (DAT_ffffc9c8 < 0.01)) ||
       ((((DAT_ffffc9c0 < DAT_ffffca18 || (uVar1 = (uint)DAT_ffffca3c, uVar1 != 0)) &&
         ((DAT_ffffc9c0 < 50.0 || (DAT_ffffca3c == '\0')))) ||
        (uVar1 = (uint)DAT_ffffca48, uVar1 != 1)))) {
      DAT_ffffca45 = 0;
    }
    else {
      DAT_ffffca45 = 1;
    }
  }
  if (DAT_ffffca46 == '\0') {
    DAT_ffffca3c = '\0';
  }
  else {
    uVar1 = (uint)DAT_ffffca45;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u8_saturate((int)DAT_ffffca3c,1);
      DAT_ffffca3c = (char)uVar1;
    }
  }
  return uVar1;
}



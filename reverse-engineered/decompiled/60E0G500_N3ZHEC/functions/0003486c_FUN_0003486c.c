/* ROM address: 0x0003486c; body bytes: 274; decompiled */

uint FUN_0003486c(void)

{
  uint uVar1;
  
  if ((((((DAT_ffffa428 == '\0') || (DAT_ffffb5b8 < 2000.0)) || (7000.0 < DAT_ffffb5b8)) ||
       ((DAT_ffffc125 == '\x01' || (DAT_ffffaa10 < 255.0)))) ||
      (((120.0 < DAT_ffffaa10 || ((DAT_ffffae54 < 255.0 || (150.0 < DAT_ffffae54)))) ||
       (DAT_ffffadbc <= 33.6)))) ||
     ((((DAT_ffffc11e < 0xfa || (DAT_ffffb5aa == '\x01')) || (DAT_ffffc120 < 0xfa)) ||
      ((DAT_ffffc12c < 0.5 || ((DAT_ffffc122 != 0 && (DAT_ffffb5a4 == '\0')))))))) {
    DAT_ffffc0c8 = 0;
  }
  else {
    DAT_ffffc0c8 = 1;
  }
  if (DAT_ffffa370 < 2.5) {
    if (DAT_ffffa370 < 2.0) {
      DAT_ffffc126 = 0;
    }
  }
  else {
    DAT_ffffc126 = 1;
  }
  uVar1 = (uint)DAT_ffffc0c8;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffc126, uVar1 == 1)) {
    uVar1 = FUN_00002478((int)DAT_ffffc0c7,1);
    DAT_ffffc0c7 = (char)uVar1;
  }
  else {
    DAT_ffffc0c7 = 0;
  }
  return uVar1;
}



/* ROM address: 0x0002ac12; body bytes: 154; decompiled */

void FUN_0002ac12(void)

{
  if (((DAT_ffffaa40 < 65.0) || (DAT_ffffb5b8 < 5500.0)) || (DAT_ffffa428 != '\0')) {
    if (((DAT_ffffbc46 & 0x800) == 0x800) && ((DAT_ffffbbca & 0x800) != 0x800)) {
      DAT_ffffbbc4 = 900000;
    }
    else if ((DAT_ffffaada == '\0') && (DAT_ffffbbc4 != 0)) {
      DAT_ffffbbc4 = DAT_ffffbbc4 + -1;
    }
  }
  else {
    DAT_ffffbbc4 = 0;
  }
  if (((DAT_ffffbc46 & 0x800) == 0x800) && (DAT_ffffbbc4 == 0)) {
    DAT_ffffbbb1 = 1;
  }
  else {
    DAT_ffffbbb1 = 0;
  }
  DAT_ffffbbca = DAT_ffffbc46;
  return;
}



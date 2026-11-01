/* ROM address: 0x00046dce; body bytes: 274; decompiled */

uint FUN_00046dce(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  if (DAT_ffffad8c < 72.2) {
    if (DAT_ffffad8c < 70.7) {
      DAT_ffffcc98 = 0;
    }
  }
  else {
    DAT_ffffcc98 = 1;
  }
  if (DAT_ffffae54 < -10.0) {
    if (DAT_ffffae54 < -10.0) {
      DAT_ffffcc99 = 0;
    }
  }
  else {
    DAT_ffffcc99 = 1;
  }
  fVar2 = DAT_ffffae58;
  fVar3 = DAT_ffffaa1c;
  uVar1 = FUN_000671a4(0x3c);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    uVar1 = FUN_000671a4(0x3d);
    uVar1 = uVar1 & 0xff;
    if (((uVar1 == 0) &&
        ((((130.0 <= fVar3 && (130.0 <= fVar2)) || (fVar3 < 130.0)) || (fVar2 < 130.0)))) &&
       ((((uVar1 = (uint)DAT_ffffcc98, uVar1 == 1 && (uVar1 = (uint)DAT_ffffcc99, uVar1 == 1)) &&
         (uVar1 = (uint)DAT_ffffa7c4, uVar1 == 1)) &&
        ((DAT_ffffbc1c == 0.0 && (uVar1 = (uint)DAT_ffffd201, uVar1 == 0)))))) {
      DAT_ffffcc88 = 1;
      return 0;
    }
  }
  DAT_ffffcc88 = 0;
  return uVar1;
}



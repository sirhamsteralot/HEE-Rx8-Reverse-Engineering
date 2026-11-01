/* ROM address: 0x0003238c; body bytes: 282; decompiled */

uint FUN_0003238c(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = DAT_ffffaa10;
  if (DAT_ffffc724 == '\0') {
    fVar3 = DAT_ffffae54;
    fVar2 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
    DAT_ffffbfdc = fVar2 - fVar4;
    if (((((DAT_ffffc532 < 0x169) || (((int)DAT_ffffcd4c & 0x80U) != 0)) &&
         ((20.0 < DAT_ffffbfdc ||
          (fVar2 = (float)FUN_0003eb72(DAT_ffffaa1c,&DAT_ffff8738), 350.0 < fVar2)))) &&
        ((DAT_ffffbfdc <= 20.0 && (35.0 < DAT_ffffc6b4)))) ||
       ((fVar4 <= -10.0 || ((35.0 < fVar4 || (40.0 < fVar3)))))) {
      DAT_ffffbfda = 0;
    }
    else {
      DAT_ffffbfda = 1;
    }
  }
  else {
    fVar3 = DAT_ffffae54;
    DAT_ffffbfdc = rx8_absolute_difference(DAT_ffffae54,DAT_ffffaa10);
    if ((((5.5 < DAT_ffffbfdc) || (fVar4 <= -10.0)) || (35.0 < fVar4)) || (40.0 < fVar3)) {
      DAT_ffffbfda = 0;
    }
    else {
      DAT_ffffbfda = 1;
    }
  }
  uVar1 = (uint)DAT_ffffbfda;
  if (uVar1 == 1) {
    uVar1 = FUN_000020c4(fVar4,&PTR_DAT_0006b1bc);
    DAT_ffffbfd8 = (undefined2)uVar1;
  }
  else {
    DAT_ffffbfd8 = 0;
  }
  return uVar1;
}



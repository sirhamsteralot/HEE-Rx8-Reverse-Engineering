/* ROM address: 0x0001cb94; body bytes: 180; decompiled */

undefined4 FUN_0001cb94(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float extraout_fr0;
  
  if (DAT_ffffa428 == '\0') {
    fVar2 = rx8_absolute_difference(DAT_ffffaa10,DAT_ffffae54);
    uVar1 = extraout_r0;
    if ((fVar2 < 7.5) && (DAT_ffffae54 < 50.0)) {
      uVar1 = FUN_0003ec20(DAT_ffffae54,&DAT_ffff80e4);
    }
  }
  else {
    fVar2 = DAT_ffffae54;
    fVar3 = (float)FUN_0003eb72(DAT_ffff9f60,&DAT_ffff80e4);
    fVar2 = fVar2 - fVar3;
    uVar1 = FUN_0003eb72(DAT_ffff9f60,&DAT_ffff80e4);
    if (extraout_fr0 <= DAT_ffffae54) {
      if (50.0 <= fVar2) {
        fVar2 = (float)FUN_0003eb72(DAT_ffff9f60,&DAT_ffff80e4);
        fVar2 = rx8_min_float(fVar2 + 15.0,DAT_ffffae54);
        uVar1 = FUN_0003ec20(fVar2,&DAT_ffff80e4);
      }
    }
    else {
      fVar2 = (float)FUN_0003eb72(DAT_ffff9f60,&DAT_ffff80e4);
      fVar2 = rx8_first_order_filter(DAT_ffffae54,fVar2,0.25,1e-05);
      uVar1 = FUN_0003ec20(fVar2,&DAT_ffff80e4);
    }
  }
  return uVar1;
}



/* ROM address: 0x0004c260; body bytes: 342; decompiled */

undefined ** FUN_0004c260(void)

{
  uint uVar1;
  undefined **ppuVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float arg1;
  float arg0;
  
  arg1 = DAT_ffffaa10;
  fVar5 = DAT_ffffae54;
  arg0 = DAT_ffffce70;
  fVar3 = rx8_max_float(DAT_ffffae54,5.0);
  fVar3 = (float)FUN_0003eb72(fVar3,&DAT_ffff879c);
  fVar4 = rx8_absolute_difference(arg0,arg1);
  fVar5 = rx8_absolute_difference(fVar3,fVar5);
  if (arg1 <= -10.0) {
    uVar1 = FUN_0003eaa4(&DAT_ffff8798,4);
  }
  else {
    uVar1 = FUN_0003eaa4(&DAT_ffff8798,0);
  }
  ppuVar2 = (undefined **)(uint)DAT_ffffa41c;
  if (ppuVar2 != (undefined **)&UNK_00000001) {
    return ppuVar2;
  }
  if ((arg0 < -10.0) &&
     (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 == (undefined **)&UNK_00000001)) {
    DAT_ffffce84 = 1;
    goto LAB_0004c3f8;
  }
  if ((arg0 < -10.0) &&
     (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 == (undefined **)&UNK_00000002)) {
    DAT_ffffce84 = 2;
    goto LAB_0004c3f8;
  }
  if ((1.875 <= fVar4) || (1.875 <= fVar5)) {
LAB_0004c3c4:
    if ((arg0 < -5.0) &&
       (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 == (undefined **)&UNK_00000003)) {
      DAT_ffffce84 = 4;
      goto LAB_0004c3f8;
    }
  }
  else {
    ppuVar2 = (undefined **)&DAT_0000493e;
    if ((DAT_ffffce7c < &DAT_0000493e) &&
       (((ppuVar2 = (undefined **)&DAT_0007cbd0, DAT_ffffce80 < 10 && (arg0 < -5.0)) &&
        (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 == (undefined **)&UNK_00000003)))) {
      DAT_ffffce84 = 3;
      goto LAB_0004c3f8;
    }
    if (((1.875 <= fVar4) || (1.875 <= fVar5)) ||
       ((ppuVar2 = &PTR_DAT_0007cbe0, (undefined *)((int)&DAT_0000493c + 1) < DAT_ffffce7c ||
        (ppuVar2 = (undefined **)&DAT_0007cbd0, 9 < DAT_ffffce80)))) goto LAB_0004c3c4;
  }
  if ((-5.0 <= arg0) ||
     (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 != (undefined **)&UNK_00000004)) {
    DAT_ffffce84 = 0;
    return ppuVar2;
  }
  DAT_ffffce84 = 5;
LAB_0004c3f8:
  return (undefined **)(uVar1 & 0xff);
}



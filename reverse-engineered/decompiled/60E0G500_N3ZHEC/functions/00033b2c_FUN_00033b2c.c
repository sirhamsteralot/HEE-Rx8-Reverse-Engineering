/* ROM address: 0x00033b2c; body bytes: 170; decompiled */

undefined4 FUN_00033b2c(void)

{
  char cVar2;
  undefined4 extraout_r0;
  undefined4 uVar1;
  float fVar3;
  float fVar4;
  float arg0;
  
  arg0 = 0.0;
  uVar1 = DAT_ffffaa10;
  cVar2 = FUN_00002440(DAT_ffffc084,0,0x3727c5ac);
  if ((cVar2 == '\0') && (DAT_ffffa428 == '\x01')) {
    uVar1 = 1;
    DAT_ffffc084 = arg0;
    DAT_ffffc088 = arg0;
    DAT_ffffc08c = arg0;
  }
  else {
    if (DAT_ffffb13b == '\0') {
      fVar3 = (float)FUN_00002068(uVar1,&DAT_0006b308);
      fVar4 = (float)FUN_00002068(uVar1,&DAT_0006b31c);
      fVar4 = DAT_ffffc08c - fVar4;
      DAT_ffffc088 = rx8_max_float(arg0,DAT_ffffc088 - fVar3);
      DAT_ffffc08c = rx8_max_float(arg0,fVar4);
    }
    fVar3 = rx8_max_float(DAT_ffffc088,DAT_ffffc08c);
    DAT_ffffc084 = rx8_max_float(arg0,fVar3);
    uVar1 = extraout_r0;
  }
  return uVar1;
}



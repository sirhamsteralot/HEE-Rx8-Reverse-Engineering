/* ROM address: 0x00035638; body bytes: 356; decompiled */

uint FUN_00035638(void)

{
  uint uVar1;
  char cVar2;
  uint extraout_r0;
  float fVar3;
  float arg2;
  float fVar4;
  float fVar5;
  float fVar6;
  
  uVar1 = (uint)DAT_ffffb5a4;
  fVar5 = DAT_ffffc21c;
  if (uVar1 == 1) {
    fVar4 = DAT_ffffaa14;
    fVar6 = DAT_ffffb5b8;
    DAT_ffffc224 = (float)FUN_00002068(DAT_ffffbc1c,&PTR_DAT_0006b6b8);
    DAT_ffffc228 = (float)FUN_00002068(fVar6,&DAT_0006b6cc);
    arg2 = 1.0;
    fVar5 = 0.0;
    fVar3 = rx8_clamp_float((680.0 - fVar6) / 130.0,0.0,1.0);
    DAT_ffffc210 = DAT_ffffc224 * fVar3;
    DAT_ffffc214 = rx8_max_float(DAT_ffffc218 - DAT_ffffc228,fVar5);
    DAT_ffffc218 = rx8_max_float(DAT_ffffc210,DAT_ffffc214);
    if (fVar6 < 680.0) {
      if (fVar6 < 672.1875) {
        DAT_ffffc22c = '\0';
      }
    }
    else {
      DAT_ffffc22c = '\x01';
    }
    if (fVar4 < 70.0) {
      if (fVar4 < 65.0) {
        DAT_ffffc22d = '\0';
      }
    }
    else {
      DAT_ffffc22d = '\x01';
    }
    cVar2 = FUN_00002440(DAT_ffffc218,fVar5,0x3727c5ac);
    if (((DAT_ffffa854 == '\x01') && (DAT_ffffc22c == '\0')) && (DAT_ffffc22d == '\x01')) {
      DAT_ffffc220 = '\x01';
    }
    else if (cVar2 == '\0') {
      DAT_ffffc220 = '\0';
    }
    uVar1 = (uint)DAT_ffffb5aa;
    if (uVar1 == 1) {
      if (DAT_ffffc220 != '\0') {
        fVar5 = rx8_clamp_float((fVar4 - 70.0) / 10.0,fVar5,arg2);
        uVar1 = extraout_r0;
        fVar5 = DAT_ffffc218 * fVar5;
      }
    }
    else {
      DAT_ffffc21c = DAT_ffffc224;
      fVar5 = DAT_ffffc21c;
    }
  }
  DAT_ffffc21c = fVar5;
  return uVar1;
}



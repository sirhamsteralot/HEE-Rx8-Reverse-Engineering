/* ROM address: 0x0002c026; body bytes: 440; decompiled */

void FUN_0002c026(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  float arg1;
  
  cVar4 = DAT_ffffbb8c;
  cVar3 = DAT_ffffa428;
  cVar2 = DAT_ffffa40a;
  cVar1 = DAT_ffffa401;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffbc31 = -2;
  }
  if ((((DAT_ffffbc54 == 0) || (DAT_ffffbb8c == '\x01')) || (DAT_ffffa428 == '\0')) ||
     ((DAT_ffffa40a == '\x01' || (DAT_ffffa401 == '\x01')))) {
    DAT_ffffbc32 = 0xfe;
  }
  arg1 = 0.0;
  uVar7 = 0x3ec99326;
  fVar5 = (float)FUN_00002500(0x3ec99326,0,(int)DAT_ffffbc31);
  DAT_ffffbc48 = DAT_ffffbd0c - (((DAT_ffffbb88 * fVar5) / 100.0 - DAT_ffffbd24) - DAT_ffffbd28);
  fVar8 = DAT_ffffbd0c;
  DAT_ffffbc60 = rx8_first_order_filter(fVar5,DAT_ffffbc60,0.25,0.19685039);
  DAT_ffffbc5f = FUN_000024d0(DAT_ffffbc60,uVar7,arg1);
  if (((DAT_ffffbc52 == 0) || (cVar4 != '\0')) || ((cVar2 != '\0' || (cVar1 != '\0')))) {
    fVar5 = DAT_ffffbc3c + 0.5;
  }
  else if ((DAT_ffffbc31 == -2) || (cVar3 != '\x01')) {
    fVar5 = 512.0;
    DAT_ffffbc4c = arg1;
  }
  else {
    fVar6 = (float)FUN_00002500(uVar7,arg1,(int)DAT_ffffbc5f);
    fVar6 = rx8_absolute_difference(fVar5,fVar6);
    fVar8 = fVar8 - DAT_ffffbc48;
    fVar5 = arg1;
    if (fVar6 < 100.0) {
      fVar8 = (fVar8 - DAT_ffffbc48 * 0.1) - (DAT_ffffbc48 + DAT_ffffbc4c) * 0.001;
      fVar5 = DAT_ffffbc48 + DAT_ffffbc4c;
    }
    DAT_ffffbc4c = fVar5;
    fVar6 = (float)FUN_00002068(DAT_ffffae54,&DAT_0006b1c8);
    fVar5 = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006b1dc);
    fVar5 = fVar8 * fVar6 * fVar5;
  }
  DAT_ffffbc3c = rx8_clamp_float(fVar5,arg1,512.0);
  return;
}



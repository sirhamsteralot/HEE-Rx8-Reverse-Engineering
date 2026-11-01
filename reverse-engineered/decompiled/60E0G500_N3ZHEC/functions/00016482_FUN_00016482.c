/* ROM address: 0x00016482; body bytes: 344; decompiled */

void FUN_00016482(void)

{
  char cVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  cVar1 = DAT_ffffa428;
  fVar6 = 0.0;
  if (DAT_ffffa8b8 == '\x01') {
    DAT_ffffa8b4 = 0.0;
    DAT_ffffa8bc = 0.0;
    DAT_ffffa8c0 = 0.0;
    DAT_ffffa8cd = '\0';
    DAT_ffffa8ce = '\0';
  }
  else {
    if (DAT_ffffa7bc + 3.0 <= DAT_ffffb5b8) {
      DAT_ffffa8cd = '\x01';
      DAT_ffffa8ce = '\x01';
    }
    fVar4 = DAT_ffffae54;
    fVar5 = DAT_ffffaa14;
    if (DAT_ffffce6e == '\x01') {
      DAT_ffffa8c8 = (float)FUN_00002068(DAT_ffffaa14,&DAT_00069bb0);
    }
    else {
      DAT_ffffa8c8 = 0.0;
    }
    if (DAT_ffffbfd4 == '\x01') {
      pfVar2 = (float *)&DAT_0006ec20;
    }
    else {
      pfVar2 = (float *)&DAT_0006ec1c;
    }
    if (cVar1 == '\0') {
      fVar3 = (float)FUN_00002068(fVar5);
      DAT_ffffa8bc = DAT_ffffa8c8 + fVar3;
      DAT_ffffa8cd = '\0';
    }
    else if ((DAT_ffffa8cd == '\x01') &&
            (DAT_ffffa8bc = rx8_max_float(DAT_ffffa8bc - *pfVar2,fVar6), DAT_ffffa8bc <= 0.0)) {
      DAT_ffffa8cd = '\0';
    }
    if (cVar1 == '\0') {
      if ((90.0 <= fVar5) && (40.0 <= fVar4)) {
        fVar6 = (float)FUN_00002068(fVar4,&DAT_00069c00);
      }
      DAT_ffffa8c4 = fVar6;
      fVar6 = (float)FUN_00002068(fVar5,&DAT_00069bec);
      DAT_ffffa8c0 = DAT_ffffa8c4 + fVar6;
      DAT_ffffa8ce = '\0';
    }
    else if ((DAT_ffffa8ce == '\x01') &&
            (DAT_ffffa8c0 = rx8_max_float(DAT_ffffa8c0 - 0.00023,fVar6), DAT_ffffa8c0 <= 0.0)) {
      DAT_ffffa8ce = '\0';
    }
    DAT_ffffa8b4 = rx8_max_float(DAT_ffffa8bc,DAT_ffffa8c0);
  }
  return;
}



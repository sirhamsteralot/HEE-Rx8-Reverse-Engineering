/* ROM address: 0x00048d00; body bytes: 220; decompiled */

void FUN_00048d00(void)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  float arg0;
  
  cVar2 = DAT_ffffcce2;
  bVar1 = DAT_ffffccd2;
  fVar3 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  arg0 = fVar3 + 5.0;
  if ((bVar1 < 3) && (cVar2 == '\x01')) {
    DAT_ffffccec = 1;
  }
  else {
    DAT_ffffccec = 0;
  }
  if ((((bVar1 < 3) || (DAT_ffffccf1 != '\0')) || (cVar2 != '\x01')) &&
     (((2 < DAT_ffffccf0 || (bVar1 < 3)) || (cVar2 != '\x01')))) {
    if (DAT_ffffccee < 0x40) {
      DAT_ffffcce8 = rx8_min_float(arg0,DAT_ffffb314 + fVar3);
      DAT_ffffccee = FUN_00002460((int)(short)DAT_ffffccee,1);
    }
    else {
      DAT_ffffcce8 = rx8_min_float(arg0,DAT_ffffcce8 + 0.007999999);
    }
  }
  else {
    DAT_ffffcce8 = rx8_min_float(arg0,DAT_ffffb314 + fVar3);
    DAT_ffffccee = 0;
  }
  DAT_ffffccf1 = cVar2;
  DAT_ffffccf0 = bVar1;
  return;
}



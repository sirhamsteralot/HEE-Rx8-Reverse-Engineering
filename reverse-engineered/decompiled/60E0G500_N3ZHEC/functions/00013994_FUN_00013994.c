/* ROM address: 0x00013994; body bytes: 208; decompiled */

void FUN_00013994(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  cVar1 = DAT_ffffa740;
  fVar3 = 0.0;
  if (DAT_ffffa748 == '\0') {
    fVar4 = 0.0;
    fVar2 = fVar3;
  }
  else if (DAT_ffffa749 == '\0') {
    fVar4 = (float)FUN_00002068(DAT_ffffb5b8,DAT_ffffa744,&PTR_LAB_0006b3f4);
    fVar2 = fVar3;
    DAT_ffffa74c = fVar4;
  }
  else {
    fVar2 = DAT_ffffa73c;
    fVar4 = DAT_ffffa744;
    if (DAT_ffffa75c == '\0') {
      if (DAT_ffffa740 == '\x01') {
        fVar4 = 0.0;
        fVar2 = fVar3;
      }
    }
    else if (DAT_ffffa740 == '\x01') {
      if (DAT_ffffc0c7 != '\0') {
        fVar2 = DAT_ffffa73c - 2.5;
      }
      if (DAT_ffffc0c4 == '\x01') {
        fVar4 = DAT_ffffa744 - 1.0;
      }
    }
  }
  DAT_ffffa73c = (float)FUN_00013c3a(fVar2);
  DAT_ffffa744 = (float)FUN_00013bd4(fVar4);
  DAT_ffffa734 = FUN_00013c4e(DAT_ffffa73c + DAT_ffffa744);
  DAT_ffffa738 = DAT_ffffa734;
  DAT_ffffa75c = cVar1;
  return;
}



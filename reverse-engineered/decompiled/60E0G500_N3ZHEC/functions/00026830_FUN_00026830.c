/* ROM address: 0x00026830; body bytes: 1008; decompiled */

void FUN_00026830(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  
  cVar3 = DAT_ffffb13d;
  cVar2 = DAT_ffffaae0;
  cVar1 = DAT_ffffaada;
  if (DAT_ffffaa10 <= 150.0) {
    if (DAT_ffffaa10 <= 145.0) {
      DAT_ffffb6ba = '\x01';
    }
  }
  else {
    DAT_ffffb6ba = '\0';
  }
  if (DAT_ffffae54 <= 150.0) {
    if (DAT_ffffae54 <= 145.0) {
      DAT_ffffb6bb = '\x01';
    }
  }
  else {
    DAT_ffffb6bb = '\0';
  }
  if (DAT_ffffaa10 < 150.0) {
    if (DAT_ffffaa10 < 145.0) {
      DAT_ffffb6bc = '\0';
    }
  }
  else {
    DAT_ffffb6bc = '\x01';
  }
  if (DAT_ffffc71c <= 0.0) {
    if (DAT_ffffc71c <= 0.0) {
      DAT_ffffb68a = '\x01';
    }
  }
  else {
    DAT_ffffb68a = '\0';
  }
  if ((((DAT_ffffb6ba == '\x01') || (DAT_ffffb6bb == '\x01')) ||
      ((DAT_ffffb5a4 == '\0' && (DAT_ffffcabc == '\0')))) ||
     (((((DAT_ffffb680 == 0 || (DAT_ffffb622 == '\x01')) || (DAT_ffffb620 == '\x01')) ||
       ((DAT_ffffb621 == '\x01' || (DAT_ffffc656 == '\x01')))) || (DAT_ffffc64b == '\x01')))) {
    DAT_ffffb686 = '\x01';
  }
  else {
    DAT_ffffb686 = '\0';
  }
  if ((DAT_ffffb687 != '\x01') || (5.0 < DAT_ffffbc1c)) {
    DAT_ffffb680 = 0x124;
  }
  else if (DAT_ffffb680 != 0) {
    DAT_ffffb680 = DAT_ffffb680 + -1;
  }
  fVar5 = DAT_ffffb6c8;
  fVar6 = DAT_ffffbc1c;
  DAT_ffffb694 = (float)FUN_00002068(DAT_ffffb634,&DAT_0006aaa8);
  DAT_ffffb698 = (float)FUN_00002068(DAT_ffffb634,&DAT_0006aae4);
  DAT_ffffb69c = (float)FUN_00002068(DAT_ffffb634,&DAT_0006aaf8);
  cVar4 = DAT_ffffb689;
  if (((((((cVar2 == '\x01') && (DAT_ffffb6b4 < 4)) || (DAT_ffffb686 == '\x01')) ||
        (DAT_ffffad90 == '\x01')) || ((cVar1 == '\x01' && (cVar3 == '\x01')))) ||
      ((fVar6 < 20.0 || ((DAT_ffffb66c < 20.0 || (20.0 <= DAT_ffffb614)))))) ||
     (fVar5 < DAT_ffffb694 - DAT_ffffb69c)) {
    DAT_ffffb687 = '\0';
LAB_00026b1a:
    if (((cVar2 == '\x01') && (3 < DAT_ffffb6b4)) &&
       ((cVar3 == '\x01' && ((DAT_ffffb686 == '\0' && (cVar1 == '\x01')))))) {
      DAT_ffffb688 = '\x01';
      goto LAB_00026b58;
    }
  }
  else if (cVar2 == '\x01') {
    if ((((3 < DAT_ffffb6b4) && (50.0 <= DAT_ffffb66c)) && (DAT_ffffb614 < 50.0)) &&
       (DAT_ffffb694 - DAT_ffffb698 <= fVar5)) {
      DAT_ffffb687 = '\x01';
    }
    goto LAB_00026b1a;
  }
  DAT_ffffb688 = '\0';
LAB_00026b58:
  DAT_ffffb6bd = DAT_ffffb689;
  if ((DAT_ffffb687 == '\0') && (DAT_ffffb688 == '\0')) {
    DAT_ffffb689 = '\x01';
  }
  else {
    DAT_ffffb689 = '\0';
  }
  if (((cVar2 == '\x01') && (DAT_ffffb6b4 < 4)) || ((DAT_ffffb689 == '\x01' && (cVar4 == '\0')))) {
    DAT_ffffb66c = 40.0;
  }
  else if (((DAT_ffffb689 == '\x01') && (20.0 <= fVar6)) || (DAT_ffffb688 == '\x01')) {
    DAT_ffffb66c = rx8_min_float(DAT_ffffb66c + 0.0009999999,0.0);
  }
  else if (DAT_ffffb687 == '\x01') {
    DAT_ffffb66c = rx8_max_float(DAT_ffffb66c - 0.0009999999,-4.0);
  }
  if (DAT_ffffb688 == '\x01') {
    DAT_ffffb6a0 = (float)FUN_00002068(&DAT_0006ab0c);
    fVar5 = rx8_min_float(DAT_ffffb60c + 0.2,DAT_ffffb694);
    DAT_ffffb68c = DAT_ffffb6a0 + fVar5;
  }
  else if (DAT_ffffb689 == '\x01') {
    DAT_ffffb68c = DAT_ffffb694;
    if ((DAT_ffffb68a == '\x01') && (DAT_ffffb6bc == '\x01')) {
      DAT_ffffb68c = 14.2;
    }
  }
  else if (DAT_ffffb687 == '\x01') {
    DAT_ffffb6a4 = (float)FUN_00002068(DAT_ffffb634,&DAT_0006ab20);
    fVar5 = rx8_max_float(DAT_ffffb60c - 0.2,DAT_ffffb694);
    DAT_ffffb68c = fVar5 - DAT_ffffb6a4;
  }
  DAT_ffffb60c = (float)FUN_0005d348(DAT_ffffb68c);
  if (cVar2 == '\x01') {
    DAT_ffffb6b4 = FUN_00002478((int)(char)DAT_ffffb6b4,1);
  }
  else {
    DAT_ffffb6b4 = 0;
  }
  return;
}



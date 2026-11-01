/* ROM address: 0x000397bc; body bytes: 370; decompiled */

char FUN_000397bc(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  float fVar6;
  
  fVar6 = DAT_ffffaa1c;
  DAT_ffffc580 = rx8_min_float(DAT_ffffaa1c,DAT_ffffcfd4);
  DAT_ffffc592 = FUN_000020c4(DAT_ffffc580,&DAT_0006b750);
  cVar4 = DAT_ffffc57a;
  cVar5 = DAT_ffffc579;
  cVar2 = DAT_ffffc578;
  cVar3 = DAT_ffffc577;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc577 = '\0';
    DAT_ffffc578 = '\0';
    DAT_ffffc575 = 0;
    DAT_ffffc579 = '\0';
    DAT_ffffc57a = '\0';
    DAT_ffffc576 = 0;
    cVar5 = '\x01';
  }
  else {
    if (((((DAT_ffffc592 < DAT_ffffc56c) && (-40.0 < DAT_ffffc538)) && (DAT_ffffc66e == '\0')) &&
        ((fVar6 < 71.0 && (cVar1 = FUN_000671a4(0x17), cVar1 == '\0')))) &&
       ((DAT_ffffc600 == '\0' && (DAT_ffffc656 == '\0')))) {
      if (71.25 <= DAT_ffffc660) {
        cVar4 = '\x01';
      }
      else {
        cVar2 = '\x01';
      }
    }
    cVar1 = FUN_0003eaa4(&DAT_ffff8fe4,0);
    if ((cVar1 == '\x01') && (fVar6 < 71.0)) {
      if (cVar2 == '\x01') {
        cVar3 = '\x01';
      }
      if (cVar4 == '\x01') {
        cVar5 = '\x01';
      }
    }
    DAT_ffffc577 = cVar3;
    DAT_ffffc578 = cVar2;
    if ((cVar3 == '\x01') || (cVar2 == '\x01')) {
      DAT_ffffc575 = 1;
      DAT_ffffc576 = 0;
      DAT_ffffc579 = '\0';
      DAT_ffffc57a = '\0';
      cVar5 = '\x01';
    }
    else {
      DAT_ffffc579 = cVar5;
      DAT_ffffc57a = cVar4;
      if ((cVar5 == '\x01') && (cVar5 = cVar4, cVar4 == '\x01')) {
        DAT_ffffc576 = 1;
        DAT_ffffc575 = 0;
      }
    }
  }
  return cVar5;
}



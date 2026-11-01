/* ROM address: 0x000129f4; body bytes: 460; decompiled */

void FUN_000129f4(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  float *pfVar4;
  undefined4 uVar5;
  float arg1;
  float arg0;
  float arg0_00;
  
  cVar3 = DAT_ffffb5ac;
  cVar2 = DAT_ffffa445;
  cVar1 = DAT_ffffa444;
  if ((DAT_ffffa6a2 == '\0') && (DAT_ffffb5ac == '\x01')) {
    DAT_ffffa6a0 = 0xfa;
  }
  else if (DAT_ffffa6a0 != 0) {
    DAT_ffffa6a0 = DAT_ffffa6a0 + -1;
  }
  arg1 = 0.0;
  if ((((DAT_ffffb5aa == '\x01') || (DAT_ffffa6a0 != 0)) || (DAT_ffffa67c == '\x01')) ||
     (DAT_ffffb5b8 <= DAT_ffffa7bc + 10.0)) {
    arg0_00 = 0.0;
    arg0 = 0.0;
  }
  else if ((DAT_ffffa444 == '\x01') && (DAT_ffffa445 == '\x01')) {
    arg0_00 = 0.0;
    arg0 = 0.0;
  }
  else if ((((DAT_ffffa6a5 == '\x01') && (DAT_ffffa444 == '\0')) ||
           ((DAT_ffffa6a6 == '\x01' && (DAT_ffffa445 == '\0')))) && (DAT_ffffaada == '\x01')) {
    if (DAT_ffffbdd4 == '\0') {
      pfVar4 = (float *)&DAT_00072bdc;
    }
    else {
      pfVar4 = (float *)&DAT_00072be4;
    }
    arg0_00 = 20.0;
    arg0 = *pfVar4;
  }
  else if ((DAT_ffffa68f == '\0') || (DAT_ffffaada != '\0')) {
    if (DAT_ffffa68e == '\0') {
      if (DAT_ffffaada == '\x01') {
        if (DAT_ffffbdd4 == '\0') {
          pfVar4 = (float *)&DAT_00072bec;
        }
        else {
          pfVar4 = (float *)&DAT_00072bf4;
        }
        arg0_00 = DAT_ffffa684 - 0.16;
        arg0 = DAT_ffffa688 - *pfVar4;
      }
      else {
        uVar5 = DAT_ffffa680;
        DAT_ffffa698 = (float)FUN_00002068(DAT_ffffa680,&DAT_0006a5a8);
        DAT_ffffa69c = (float)FUN_00002068(uVar5,&DAT_0006a5bc);
        arg0_00 = DAT_ffffa684 - DAT_ffffa698;
        arg0 = DAT_ffffa688 - DAT_ffffa69c;
      }
    }
    else {
      arg0_00 = 0.0;
      arg0 = 0.0;
    }
  }
  else {
    uVar5 = 0x3f000000;
    arg0_00 = (float)FUN_00002500(0x3f000000,0,0);
    arg0 = (float)FUN_00002500(uVar5,arg1,0);
  }
  DAT_ffffa684 = rx8_max_float(arg0_00,arg1);
  DAT_ffffa688 = rx8_max_float(arg0,arg1);
  DAT_ffffa6a2 = cVar3;
  DAT_ffffa6a5 = cVar1;
  DAT_ffffa6a6 = cVar2;
  return;
}



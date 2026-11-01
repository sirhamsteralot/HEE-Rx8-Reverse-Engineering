/* ROM address: 0x00023da0; body bytes: 436; decompiled */

undefined4 FUN_00023da0(void)

{
  char cVar1;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  float fVar2;
  float arg1;
  float arg0;
  
  fVar2 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  cVar1 = DAT_ffffa41c;
  if (DAT_ffffb5b8 < 500.0) {
    if (DAT_ffffb5b8 < 300.0) {
      DAT_ffffb4a5 = '\0';
    }
  }
  else {
    DAT_ffffb4a5 = '\x01';
  }
  if (((DAT_ffffce6e == '\x01') && (DAT_ffffb4a6 == '\x01')) && (DAT_ffffa41c == '\0')) {
    DAT_ffffb490 = FUN_000020c4(DAT_ffffaa10,&PTR_LAB_0006aa88);
  }
  else if (DAT_ffffb490 != 0) {
    DAT_ffffb490 = DAT_ffffb490 + -1;
  }
  if (((DAT_ffffb4a5 == '\x01') || (DAT_ffffce6e == '\0')) ||
     ((DAT_ffffa428 == '\x01' || (DAT_ffffb490 == 0)))) {
    DAT_ffffb493 = '\0';
  }
  else if (DAT_ffffa42c == '\x01') {
    DAT_ffffb493 = '\x01';
  }
  arg1 = 0.0;
  if (DAT_ffffccfb == '\x01') {
    arg0 = DAT_ffffb474 + fVar2;
    fVar2 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
  }
  else if (DAT_ffffccfc == '\x01') {
    fVar2 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
    arg0 = DAT_ffffb468;
  }
  else if (DAT_ffffccfd == '\x01') {
    arg0 = DAT_ffffccc8 + fVar2;
    fVar2 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
  }
  else {
    arg0 = DAT_ffffb480 + fVar2;
    if (DAT_ffffccec == '\x01') {
      arg1 = 0.0;
      fVar2 = fVar2 + 5.0;
    }
    else {
      if (DAT_ffffcce2 != '\x01') {
        if (DAT_ffffb493 == '\x01') {
          DAT_ffffb47c = 99.0;
          DAT_ffffb4a6 = cVar1;
          return 1;
        }
        fVar2 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
        DAT_ffffb47c = rx8_clamp_float(arg0,arg1,fVar2);
        DAT_ffffb4a6 = cVar1;
        return extraout_r0_00;
      }
      fVar2 = (float)FUN_0003eb72(0x42de0000,&DAT_ffff80b4);
      arg0 = DAT_ffffcce8;
    }
  }
  DAT_ffffb47c = rx8_clamp_float(arg0,arg1,fVar2);
  DAT_ffffb4a6 = cVar1;
  return extraout_r0;
}



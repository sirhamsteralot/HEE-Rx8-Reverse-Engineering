/* ROM address: 0x000235b8; body bytes: 646; decompiled */

undefined4 FUN_000235b8(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined4 extraout_r0;
  undefined4 uVar4;
  undefined *puVar5;
  float arg0;
  float arg1;
  float arg3;
  undefined4 uVar6;
  float fVar7;
  
  cVar3 = DAT_ffffb33e;
  cVar2 = DAT_ffffb33d;
  cVar1 = DAT_ffffb33c;
  arg3 = 1e-05;
  fVar7 = DAT_ffffaa40;
  uVar4 = DAT_ffffaa10;
  uVar6 = DAT_ffffb5b8;
  DAT_ffffb444 = rx8_first_order_filter(DAT_ffffaa40,DAT_ffffb444,0.1,1e-05);
  if (DAT_ffffb444 - fVar7 < 2.0) {
    if (DAT_ffffb444 - fVar7 < -2.0) {
      DAT_ffffb45d = '\0';
    }
  }
  else {
    DAT_ffffb45d = '\x01';
  }
  if (DAT_ffffb5a4 == '\x01') {
    if (cVar1 == '\x01') {
      puVar5 = &DAT_0006a8c4;
    }
    else {
      if (cVar2 != '\x01') {
        if (cVar3 == '\x01') {
          puVar5 = &DAT_0006a8ec;
        }
        else {
          puVar5 = &DAT_0006a900;
        }
        DAT_ffffb454 = (float)FUN_00002068(uVar6,puVar5);
        goto LAB_00023700;
      }
      puVar5 = &DAT_0006a8d8;
    }
    DAT_ffffb454 = (float)FUN_00002068(uVar6,puVar5);
  }
  else if (DAT_ffffb5aa == '\0') {
    if (DAT_ffffcabc == '\x01') {
      puVar5 = &DAT_0006a8c4;
    }
    else {
      puVar5 = &DAT_0006a8d8;
    }
    DAT_ffffb454 = (float)FUN_00002068(uVar6,puVar5);
  }
  else {
    DAT_ffffb454 = (float)FUN_00002068(uVar6,&DAT_0006a900);
  }
LAB_00023700:
  DAT_ffffb458 = (float)FUN_00002068(uVar4,&PTR_DAT_0006a914);
  DAT_ffffb448 = (float)FUN_00002068(uVar4,&PTR_DAT_0006a928);
  if (((cVar1 == '\x01') || (cVar2 == '\x01')) || (cVar3 == '\x01')) {
    puVar5 = &DAT_0006a93c;
  }
  else {
    puVar5 = &DAT_0006a950;
  }
  DAT_ffffb44c = (float)FUN_00002068(uVar6,puVar5);
  if (DAT_ffffb3fc <= DAT_ffffb44c) {
    if (DAT_ffffb3fc <= DAT_ffffb44c - 2.0) {
      DAT_ffffb45e = '\x01';
    }
  }
  else {
    DAT_ffffb45e = '\0';
  }
  if (DAT_ffffb45e != '\x01') {
    DAT_ffffb450 = 0.25;
    goto LAB_0002383e;
  }
  if (DAT_ffffb5a4 == '\x01') {
    if (cVar1 == '\x01') {
      puVar5 = &DAT_0006a964;
    }
    else {
      if (cVar2 != '\x01') {
        if (cVar3 == '\x01') {
          puVar5 = &DAT_0006a98c;
        }
        else {
          puVar5 = &DAT_0006a9a0;
        }
        DAT_ffffb460 = (float)FUN_00002068(uVar6,puVar5);
        goto LAB_00023828;
      }
      puVar5 = &DAT_0006a978;
    }
    DAT_ffffb460 = (float)FUN_00002068(uVar6,puVar5);
  }
  else if (DAT_ffffb5aa == '\0') {
    if (DAT_ffffcabc == '\x01') {
      puVar5 = &DAT_0006a964;
    }
    else {
      puVar5 = &DAT_0006a978;
    }
    DAT_ffffb460 = (float)FUN_00002068(uVar6,puVar5);
  }
  else {
    DAT_ffffb460 = (float)FUN_00002068(uVar6,&DAT_0006a9a0);
  }
LAB_00023828:
  DAT_ffffb450 = DAT_ffffb448 + DAT_ffffb460;
LAB_0002383e:
  fVar7 = 1.0;
  if (DAT_ffffb45d == '\0') {
    fVar7 = 1.0;
    arg0 = DAT_ffffb454 + DAT_ffffb458;
    arg1 = 0.0;
  }
  else {
    arg0 = DAT_ffffb450;
    arg1 = (float)FUN_00002068(uVar4,&PTR_DAT_0006a9b4);
    DAT_ffffb464 = arg1;
  }
  DAT_ffffb440 = rx8_clamp_float(arg0,arg1,fVar7);
  if ((DAT_ffffccdb == '\x01') && (DAT_ffffccdc == '\x01')) {
    DAT_ffffb3fc = 5.0;
    uVar4 = 1;
  }
  else {
    fVar7 = rx8_first_order_filter(DAT_ffffb43c,DAT_ffffb3fc,DAT_ffffb440,arg3);
    DAT_ffffb3fc = rx8_min_float(DAT_ffffb334,fVar7);
    uVar4 = extraout_r0;
  }
  return uVar4;
}



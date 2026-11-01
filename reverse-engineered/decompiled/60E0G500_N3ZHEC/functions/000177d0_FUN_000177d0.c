/* ROM address: 0x000177d0; body bytes: 642; decompiled */

void FUN_000177d0(void)

{
  float arg1;
  char cVar1;
  float arg1_00;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar8 = DAT_ffffbc1c;
  cVar1 = DAT_ffffaae0;
  if ((DAT_ffffa95d == '\0') && (DAT_ffffa93d == '\x01')) {
    DAT_ffffa939 = FUN_00002478((int)DAT_ffffa939,1);
    uVar2 = FUN_0003eaa4(&DAT_ffff8074,0);
    uVar2 = FUN_00002478(uVar2,1);
    FUN_0003ebc0(&DAT_ffff8074,uVar2);
  }
  if ((DAT_ffffa95f == '\0') && (DAT_ffffa93e == '\x01')) {
    DAT_ffffa937 = FUN_00002478((int)DAT_ffffa937,1);
    uVar2 = FUN_0003eaa4(&DAT_ffff8070,0);
    uVar2 = FUN_00002478(uVar2,1);
    FUN_0003ebc0(&DAT_ffff8070,uVar2);
  }
  if ((DAT_ffffa960 == '\0') && (DAT_ffffa940 == '\x01')) {
    DAT_ffffa938 = FUN_00002478((int)DAT_ffffa938,1);
    uVar2 = FUN_0003eaa4(&DAT_ffff8072,0);
    uVar2 = FUN_00002478(uVar2,1);
    FUN_0003ebc0(&DAT_ffff8072,uVar2);
  }
  arg1_00 = DAT_ffffae54;
  arg1 = DAT_ffffaa10;
  if (DAT_ffffa428 == '\x01') {
    uVar2 = 0;
    fVar7 = DAT_ffffb5b8;
    fVar5 = (float)FUN_00002500(0x3f800000,0,(int)DAT_ffffa974);
    fVar9 = DAT_ffffa8ec;
    fVar6 = (float)FUN_00002068(fVar5,&PTR_LAB_0006b258);
    DAT_ffffa908 = fVar7 * fVar6 * 1.5686273e-05;
    if (0.5 <= fVar9) {
      fVar9 = DAT_ffffa8ec + -0.5;
    }
    uVar3 = FUN_000024d0(fVar9,0x3f800000,uVar2);
    fVar9 = (float)FUN_00002500(0x3f800000,uVar2,uVar3);
    fVar9 = (float)FUN_00002068(fVar5 - fVar9,&PTR_LAB_0006b258);
    DAT_ffffa90c = DAT_ffffa908 - fVar7 * fVar9 * 1.5686273e-05;
    uVar3 = 0x447a0000;
    fVar7 = (float)FUN_0003ea74(DAT_ffffa90c,0x447a0000);
    DAT_ffffa910 = DAT_ffffa910 + fVar7;
    if (((0.0 < fVar8) && (80.0 <= arg1)) && (DAT_ffffa401 == '\0')) {
      fVar7 = (float)FUN_0003ea74(DAT_ffffa908,uVar3);
      DAT_ffffa920 = DAT_ffffa920 + fVar7;
      DAT_ffffa924 = DAT_ffffa924 + fVar8 * 2.222222e-06;
    }
    uVar3 = FUN_0003ea74(DAT_ffffa920,0x42700000);
    fVar8 = 1e-05;
    cVar4 = FUN_00002440(uVar3,uVar2,0x3727c5ac);
    if (cVar4 != '\0') {
      fVar7 = (float)FUN_0003ea74(DAT_ffffa924 * 1.0,uVar3);
      DAT_ffffa91c = rx8_first_order_filter(fVar7,DAT_ffffa91c,0.001,fVar8);
    }
    DAT_ffffa914 = rx8_max_float(DAT_ffffa914,arg1);
    DAT_ffffa918 = rx8_max_float(DAT_ffffa918,arg1_00);
  }
  if ((DAT_ffffa961 == '\x01') && (cVar1 == '\0')) {
    FUN_0003ec20(DAT_ffffa910,&DAT_ffff8050);
    FUN_0003ec20(DAT_ffffa91c,&DAT_ffff8068);
    FUN_0003ec20(DAT_ffffa914,&DAT_ffff8058);
    FUN_0003ec20(DAT_ffffa918,&DAT_ffff8060);
  }
  DAT_ffffa95d = DAT_ffffa93d;
  DAT_ffffa95f = DAT_ffffa93e;
  DAT_ffffa960 = DAT_ffffa940;
  DAT_ffffa961 = cVar1;
  return;
}



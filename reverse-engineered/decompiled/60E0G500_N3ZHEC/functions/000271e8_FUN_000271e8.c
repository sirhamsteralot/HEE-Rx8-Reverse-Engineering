/* ROM address: 0x000271e8; body bytes: 238; decompiled */

void FUN_000271e8(void)

{
  char cVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float arg3;
  undefined4 uVar5;
  float arg1;
  
  arg3 = 1e-05;
  fVar4 = DAT_ffffb664;
  uVar5 = DAT_ffffb650;
  cVar1 = FUN_00002440(DAT_ffffb650,DAT_ffffb610,0x3727c5ac);
  arg1 = 0.0;
  cVar2 = FUN_00002440(uVar5,0,arg3);
  fVar3 = arg1;
  if (DAT_ffffb683 != '\0') {
    if (cVar1 == '\0') {
      DAT_ffffb660 = 3.75;
      fVar3 = DAT_ffffb660;
    }
    else {
      fVar3 = (float)FUN_000020dc(DAT_ffffb608,uVar5,&LAB_0006ab34);
    }
  }
  DAT_ffffb660 = fVar3;
  DAT_ffffb664 = rx8_first_order_filter(DAT_ffffb660,DAT_ffffb664,0.1244,arg3);
  fVar4 = (float)FUN_0003ea74(DAT_ffffb664 - fVar4 * 0.9672,0x3d065950);
  DAT_ffffb668 = rx8_clamp_float(fVar4,arg1,3.75);
  if ((cVar2 != '\0') && (DAT_ffffb682 != '\x01')) {
    fVar4 = (float)FUN_00002068(DAT_ffffb668,&DAT_0006aad0);
    arg1 = rx8_clamp_float(fVar4,arg1,100.0);
  }
  DAT_ffffb690 = arg1;
  DAT_ffffb61c = FUN_0005cfa4(DAT_ffffb690);
  return;
}



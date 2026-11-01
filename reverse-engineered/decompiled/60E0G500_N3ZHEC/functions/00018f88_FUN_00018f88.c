/* ROM address: 0x00018f88; body bytes: 410; decompiled */

undefined4 FUN_00018f88(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  char cVar5;
  undefined4 extraout_r0;
  undefined4 uVar4;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  float fVar11;
  
  fVar3 = DAT_ffffbd14;
  fVar2 = DAT_ffffbd04;
  fVar11 = DAT_ffffbd00;
  cVar1 = DAT_ffffbcef;
  fVar8 = DAT_ffffbb2c;
  iVar6 = (int)DAT_ffffbcef;
  fVar9 = DAT_ffffbcfc;
  uVar4 = DAT_ffffb5b8;
  uVar10 = DAT_ffffc12c;
  fVar7 = DAT_ffffbc40;
  cVar5 = FUN_00002440(DAT_ffffbcfc,0,0x3727c5ac);
  if (cVar1 == '\x04') {
    DAT_ffffa9a0 = fVar11;
  }
  else if (cVar5 == '\0') {
    DAT_ffffa9a0 = -20.0;
  }
  else {
    if (DAT_ffffa9b4 <= DAT_ffffa9b0) {
      fVar8 = fVar7;
    }
    fVar8 = ((fVar3 - DAT_ffffbce4) - DAT_ffffbd20) - fVar8;
    fVar7 = (float)FUN_00002500(0x3f800000,0,iVar6);
    fVar8 = rx8_max_float((DAT_ffffbd24 + DAT_ffffbd28 + fVar2 + fVar8 * (4.0 / (-fVar7 + 4.0))) -
                          fVar3,0.0);
    fVar8 = (float)FUN_000046cc(fVar8 / fVar9);
    DAT_ffffa9a0 = fVar11 - fVar8;
  }
  if (cVar1 == '\x01') {
    DAT_ffffa9ac = (float)FUN_00002500(0x3f000000,0xc2480000,0x7e);
  }
  else if (cVar1 == '\x02') {
    DAT_ffffa9ac = (float)FUN_000020dc(uVar10,uVar4,&DAT_00069c7c);
  }
  else if (cVar1 == '\x03') {
    DAT_ffffa9ac = (float)FUN_00002500(0x3f000000,0xc2480000,0x7e);
  }
  else {
    DAT_ffffa9ac = (float)FUN_000020dc(uVar10,uVar4,&DAT_00069c60);
  }
  fVar8 = (float)FUN_000020dc(uVar10,uVar4,&DAT_00069c98);
  fVar11 = DAT_ffffa9a0 + fVar8;
  fVar8 = DAT_ffffa9ac + fVar8;
  DAT_ffffa9a8 = rx8_max_float(DAT_ffffa9a0,DAT_ffffa9ac);
  DAT_ffffa9a4 = rx8_max_float(fVar11,fVar8);
  uVar4 = extraout_r0;
  if (DAT_ffffa9ac < DAT_ffffa9a0) {
    uVar4 = 0;
  }
  DAT_ffffa9c0 = DAT_ffffa9ac >= DAT_ffffa9a0;
  return uVar4;
}



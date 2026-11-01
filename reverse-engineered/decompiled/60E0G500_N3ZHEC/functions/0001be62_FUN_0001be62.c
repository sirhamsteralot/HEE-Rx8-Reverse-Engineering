/* ROM address: 0x0001be62; body bytes: 526; decompiled */

uint FUN_0001be62(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  char cVar6;
  char cVar7;
  ushort uVar5;
  uint uVar4;
  float fVar8;
  float fVar9;
  float extraout_fr0;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  
  bVar3 = DAT_ffffccfc;
  cVar2 = DAT_ffffccd9;
  cVar7 = DAT_ffffccd8;
  sVar1 = DAT_ffffae00;
  fVar11 = DAT_ffffb480;
  if (DAT_ffffae49 == '\0') {
    DAT_ffffade8 = DAT_ffffb520;
    DAT_ffffadec = DAT_ffffb524;
    DAT_ffffae10 = DAT_ffffb520;
    DAT_ffffae14 = DAT_ffffb524;
    DAT_ffffae49 = '\x01';
  }
  else if (((DAT_ffffccd8 == '\0') && (DAT_ffffccd9 == '\0')) &&
          (cVar6 = FUN_0003eaa4(&DAT_ffff8764,0), cVar6 == '\0')) {
    fVar8 = 1e-05;
    DAT_ffffade8 = rx8_first_order_filter(DAT_ffffb520,DAT_ffffade8,0.5,1e-05);
    DAT_ffffadec = rx8_first_order_filter(DAT_ffffb524,DAT_ffffadec,0.5,fVar8);
  }
  fVar8 = rx8_absolute_difference(DAT_ffffade8,DAT_ffffae10);
  fVar9 = rx8_absolute_difference(DAT_ffffadec,DAT_ffffae14);
  if (((((-80.0 < DAT_ffffb52c) || (cVar7 != '\0')) ||
       ((cVar2 != '\0' || ((DAT_ffffb569 != '\0' || (0.244 <= fVar8)))))) || (0.244 <= fVar9)) ||
     ((((DAT_ffffcd01 != '\x01' || (DAT_ffffb55d != '\x01')) || (bVar3 != 0)) ||
      ((cVar7 = FUN_0003eaa4(&DAT_ffff8766,0), cVar7 != '\0' || (5.0 <= fVar11)))))) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00002460((int)sVar1,1);
  }
  uVar4 = (uint)bVar3;
  uVar12 = 0;
  if (uVar4 == 1) {
    FUN_0003ec20(0,&DAT_ffff80d4);
    uVar4 = FUN_0003ec20(uVar12,&DAT_ffff80dc);
  }
  else if (0xf < uVar5) {
    fVar9 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
    uVar4 = FUN_0003eb72(0x41700000,&DAT_ffff80ac);
    fVar8 = extraout_fr0;
    if (fVar11 + fVar9 < DAT_ffffade8 + 0.061) {
      fVar10 = (float)FUN_0003eb72(uVar12,&DAT_ffff80d4);
      fVar9 = rx8_clamp_float(((fVar10 + DAT_ffffade8) - fVar9) + 0.061,0.0,0.875);
      uVar4 = FUN_0003ec20(fVar9,&DAT_ffff80d4);
      uVar5 = 0;
    }
    if (fVar11 + fVar8 < DAT_ffffadec + 0.061) {
      fVar11 = (float)FUN_0003eb72(uVar12,&DAT_ffff80dc);
      fVar11 = rx8_clamp_float(((fVar11 + DAT_ffffadec) - fVar8) + 0.061,0.0,0.875);
      uVar4 = FUN_0003ec20(fVar11,&DAT_ffff80dc);
      uVar5 = 0;
    }
  }
  DAT_ffffae00 = uVar5;
  DAT_ffffae10 = DAT_ffffade8;
  DAT_ffffae14 = DAT_ffffadec;
  return uVar4;
}



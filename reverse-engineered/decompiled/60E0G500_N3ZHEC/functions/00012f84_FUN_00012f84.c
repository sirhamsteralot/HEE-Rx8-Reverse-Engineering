/* ROM address: 0x00012f84; body bytes: 340; decompiled */

uint FUN_00012f84(void)

{
  char cVar1;
  uint uVar2;
  float *pfVar3;
  undefined *puVar4;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float extraout_fr0;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  cVar1 = DAT_ffffa428;
  pcVar5 = FUN_00002068;
  uVar10 = DAT_ffffc12c;
  uVar8 = DAT_ffffad8c;
  uVar11 = DAT_ffffaa10;
  if ((DAT_ffffa6df == '\0') && (DAT_ffffa428 == '\x01')) {
    uVar9 = DAT_ffffaa1c;
    DAT_ffffa6c4 = (float)FUN_00002068(DAT_ffffaa1c,&DAT_00069d68);
    DAT_ffffa6c8 = (float)FUN_00002068(uVar9,&DAT_00069d7c);
  }
  else {
    if (DAT_ffffaada == '\x01') {
      pfVar3 = (float *)&DAT_0006f710;
    }
    else {
      pfVar3 = (float *)&DAT_0006f718;
    }
    fVar6 = *pfVar3 + DAT_ffffa6c8;
    DAT_ffffa6c4 = rx8_min_float(DAT_ffffa6c4 + 0.0,0.0);
    DAT_ffffa6c8 = rx8_min_float(fVar6,0.0);
  }
  if (DAT_ffffa6b9 == '\x01') {
    pcVar5 = FUN_000020dc;
    fVar6 = (float)FUN_000020dc(uVar11,uVar10,&DAT_00069d90);
    fVar7 = (float)FUN_000020dc(uVar8,uVar10,&DAT_00069dac);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)FUN_000020dc(uVar11,uVar10,&DAT_00069dc8);
    puVar4 = &DAT_00069de4;
  }
  else if (DAT_ffffa6b7 == '\x01') {
    fVar6 = (float)FUN_00002068(uVar11,&DAT_00069cc8);
    fVar7 = (float)FUN_00002068(uVar8,&DAT_00069cdc);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)FUN_00002068(uVar11,&DAT_00069cf0);
    puVar4 = &DAT_00069d04;
  }
  else {
    if (DAT_ffffa6b8 != 1) {
      DAT_ffffa6bc = DAT_ffffa6c4;
      DAT_ffffa6c0 = DAT_ffffa6c8;
      DAT_ffffa6df = cVar1;
      return (uint)DAT_ffffa6b8;
    }
    fVar6 = (float)FUN_00002068(uVar11,&DAT_00069d18);
    fVar7 = (float)FUN_00002068(uVar8,&DAT_00069d2c);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)FUN_00002068(uVar11,&DAT_00069d40);
    puVar4 = &DAT_00069d54;
  }
  uVar2 = (*pcVar5)(uVar8,puVar4);
  DAT_ffffa6c0 = fVar6 + extraout_fr0;
  DAT_ffffa6df = cVar1;
  return uVar2;
}



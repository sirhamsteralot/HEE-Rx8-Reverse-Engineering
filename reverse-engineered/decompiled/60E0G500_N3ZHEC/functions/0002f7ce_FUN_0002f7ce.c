/* ROM address: 0x0002f7ce; body bytes: 882; decompiled */

undefined4 FUN_0002f7ce(void)

{
  char cVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  cVar7 = DAT_ffffc004;
  cVar6 = DAT_ffffbe24;
  cVar5 = DAT_ffffb5ab;
  cVar4 = DAT_ffffb5aa;
  cVar3 = DAT_ffffb5a4;
  fVar2 = DAT_ffffadbc;
  cVar1 = DAT_ffffaada;
  fVar9 = DAT_ffffa7bc;
  fVar11 = DAT_ffffbc1c;
  fVar12 = DAT_ffffaa10;
  fVar13 = DAT_ffffb5b8;
  DAT_ffffbde8 = (float)FUN_00002068(DAT_ffffaa10,&PTR_LAB_0006ae30);
  DAT_ffffbdec = FUN_00002068(fVar12,&PTR_LAB_0006ae44);
  fVar10 = fVar9 + 0.0;
  if (fVar11 < 5.0) {
    if (fVar11 < 2.0) {
      DAT_ffffbe05 = '\0';
    }
  }
  else {
    DAT_ffffbe05 = '\x01';
  }
  if (fVar11 < 5.0) {
    if (fVar11 < 2.0) {
      DAT_ffffbe06 = '\0';
    }
  }
  else {
    DAT_ffffbe06 = '\x01';
  }
  if (fVar12 < 20.0) {
    if (fVar12 < 17.5) {
      DAT_ffffbe07 = '\0';
    }
  }
  else {
    DAT_ffffbe07 = '\x01';
  }
  if (fVar12 < 120.0) {
    if (fVar12 < 117.5) {
      DAT_ffffbe08 = '\0';
    }
  }
  else {
    DAT_ffffbe08 = '\x01';
  }
  if (fVar13 < 2000.0) {
    if (fVar13 < 1800.0) {
      DAT_ffffbe09 = '\0';
    }
  }
  else {
    DAT_ffffbe09 = '\x01';
  }
  if (((((DAT_ffffbe05 != '\0') || (cVar1 != '\0')) || (0x3d < DAT_ffffbdf8)) ||
      (fVar13 < fVar9 + -500.0)) ||
     (((cVar4 != '\0' && (((cVar3 != '\x01' || (cVar5 != '\0')) || (cVar7 != '\x01')))) ||
      (((fVar2 < DAT_ffffbde8 || (cVar6 != '\0')) && ((fVar2 < 8.0 || (cVar6 != '\x01')))))))) {
    if ((0x3e < DAT_ffffbdda) || ((0x1f < DAT_ffffbdda && (cVar6 == '\x01')))) {
      DAT_ffffbde0 = '\0';
    }
  }
  else {
    DAT_ffffbde0 = '\x01';
    DAT_ffffbdda = 0;
  }
  DAT_ffffbdda = FUN_00002460((int)(short)DAT_ffffbdda,1);
  if ((((DAT_ffffbe06 != '\0') || (fVar9 + -250.0 <= fVar13)) || (cVar3 != '\x01')) ||
     ((cVar5 != '\0' || (cVar7 != '\x01')))) {
    if (0x3e < DAT_ffffbddc) {
      DAT_ffffbde1 = '\0';
    }
  }
  else {
    DAT_ffffbde1 = '\x01';
    DAT_ffffbddc = 0;
  }
  DAT_ffffbddc = FUN_00002460((int)(short)DAT_ffffbddc,1);
  if (((DAT_ffffbe09 == '\0') && (DAT_ffffbe07 == '\x01')) &&
     ((DAT_ffffbe08 == '\0' && ((DAT_ffffbde0 == '\x01' || (DAT_ffffbde1 == '\x01')))))) {
    DAT_ffffbddf = 1;
  }
  else {
    DAT_ffffbddf = 0;
  }
  if (cVar1 == '\0') {
    DAT_ffffbdf8 = FUN_00002460((int)(short)DAT_ffffbdf8,1);
  }
  else {
    DAT_ffffbdf8 = 0;
  }
  uVar8 = 4;
  if (fVar9 + -250.0 <= fVar13) {
    DAT_ffffbdfa = 0;
  }
  else {
    uVar8 = FUN_00002460((int)DAT_ffffbdfa,1);
    DAT_ffffbdfa = (short)uVar8;
  }
  if (fVar13 < fVar10) {
    DAT_ffffbdfc = 0;
  }
  else {
    uVar8 = FUN_00002460((int)DAT_ffffbdfc,1);
    DAT_ffffbdfc = (short)uVar8;
  }
  return uVar8;
}



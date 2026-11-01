/* ROM address: 0x00016d7c; body bytes: 964; decompiled */

void FUN_00016d7c(void)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar6;
  ushort uVar5;
  char cVar7;
  uint uVar3;
  byte bVar8;
  byte bVar9;
  undefined4 uVar4;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  float fVar18;
  
  uVar2 = DAT_ffffae54;
  uVar4 = DAT_ffffad8c;
  cVar1 = DAT_ffffaada;
  fVar15 = DAT_ffffaa10;
  fVar16 = DAT_ffffb5b8;
  DAT_ffffa8f0 = FUN_00002120(DAT_ffffb5b8,DAT_ffffc12c,&DAT_0006b264);
  DAT_ffffa8e8 = (float)FUN_00002068(fVar15,&PTR_LAB_0006b220);
  bVar6 = FUN_000020ac(fVar15,&DAT_0006b1f0);
  DAT_ffffa932 = '2';
  DAT_ffffa933 = FUN_00002120(fVar16,DAT_ffffadbc,&DAT_0006b278);
  uVar5 = FUN_000020c4(DAT_ffffaa1c,&PTR_PTR_0006b234);
  DAT_ffffa936 = FUN_000020ac(uVar2,&DAT_0006b214);
  uVar17 = 0;
  cVar7 = FUN_00002440(DAT_ffffbc1c,0,0x3727c5ac);
  if (((((cVar1 != '\x01') || (DAT_ffffa952 < 0x271)) || (DAT_ffffa428 != '\x01')) ||
      ((cVar7 != '\0' || (DAT_ffffa954 < 0xfa)))) ||
     ((fVar15 < 255.0 || ((DAT_ffffc68e != '\0' || (DAT_ffffccd1 != '\0')))))) {
    DAT_ffffa93a = 'd';
  }
  else {
    DAT_ffffa93a = FUN_000020ac(DAT_ffffbe6c,&PTR_PTR_0006b208);
  }
  if (cVar1 == '\x01') {
    DAT_ffffa952 = FUN_00002460((int)(short)DAT_ffffa952,1);
  }
  else {
    DAT_ffffa952 = 0;
  }
  if (cVar7 == '\0') {
    DAT_ffffa954 = FUN_00002460((int)(short)DAT_ffffa954,1);
  }
  else {
    DAT_ffffa954 = 0;
  }
  fVar18 = 1.0;
  fVar10 = (float)FUN_00002500(0x3f800000,uVar17,(int)(char)DAT_ffffa8f0);
  fVar11 = (float)FUN_00002500(fVar18,0xc2480000,(int)DAT_ffffa932);
  fVar12 = (float)FUN_00002500(fVar18,uVar17,(int)DAT_ffffa936);
  fVar13 = (float)FUN_00002500(fVar18,0xc2c80000,(int)DAT_ffffa93a);
  fVar13 = fVar11 + fVar12 + DAT_ffffa8e8 * fVar10 + fVar13;
  if (0.5 <= fVar13) {
    fVar13 = fVar13 + -0.5;
  }
  uVar3 = FUN_000024d0(fVar13,fVar18,uVar17);
  if (DAT_ffffa422 < uVar5) {
    DAT_ffffa934 = 0x1e;
  }
  else {
    DAT_ffffa934 = 0;
  }
  if ((((DAT_ffffa428 == '\0') || (0x1d < DAT_ffffa974)) || (fVar15 < 255.0)) ||
     ((5000.0 < fVar16 || ((DAT_ffffa92c != 0 && (DAT_ffffa948 == 0)))))) {
    DAT_ffffa928 = (undefined *)0x57e4;
  }
  else if (DAT_ffffa928 != (undefined *)0x0) {
    DAT_ffffa928 = DAT_ffffa928 + -1;
  }
  DAT_ffffa948 = DAT_ffffa92c;
  if (DAT_ffffa928 == (undefined *)0x0) {
    uVar14 = FUN_00002068(DAT_ffffa91c,&PTR_PTR_0006b240);
    fVar15 = (float)FUN_0003ea74(uVar14,0x41000000);
    fVar15 = fVar15 + 0.5;
    if (fVar15 <= 4.294967e+09) {
      if (0.0 <= fVar15) {
        if (2.1474836e+09 < fVar15) {
          fVar15 = fVar15 + -4.2949673e+09;
        }
        DAT_ffffa92c = (int)fVar15;
      }
      else {
        DAT_ffffa92c = 0;
      }
    }
    else {
      DAT_ffffa92c = -1;
    }
  }
  else if (DAT_ffffa92c != 0) {
    DAT_ffffa92c = DAT_ffffa92c + -1;
  }
  if (DAT_ffffa92c == 0) {
    DAT_ffffa935 = 0;
  }
  else {
    bVar8 = FUN_000020ac(uVar2,&PTR_PTR_0006b1fc);
    bVar9 = FUN_00002120(fVar16,uVar4,&PTR_DAT_0006b28c);
    DAT_ffffa935 = bVar8;
    if (bVar9 < bVar8) {
      DAT_ffffa935 = bVar9;
    }
  }
  if ((uVar3 & 0xff) < (uint)bVar6) {
    uVar3 = (uint)(char)bVar6;
  }
  if ((uVar3 & 0xff) < (uint)DAT_ffffa933) {
    uVar3 = (int)(char)DAT_ffffa933;
  }
  if ((uVar3 & 0xff) < (uint)DAT_ffffa934) {
    uVar3 = (int)(char)DAT_ffffa934;
  }
  if ((uVar3 & 0xff) < (uint)DAT_ffffa935) {
    uVar3 = (int)(char)DAT_ffffa935;
  }
  fVar15 = DAT_ffffa8ec;
  if (0.5 <= DAT_ffffa8ec) {
    fVar15 = DAT_ffffa8ec + -0.5;
  }
  uVar4 = FUN_000024d0(fVar15,fVar18,uVar17);
  uVar3 = FUN_00002478(uVar3,uVar4);
  if (0x3c < (uVar3 & 0xff)) {
    uVar3 = 0x3c;
  }
  fVar15 = (float)FUN_00002500(fVar18,uVar17,(int)DAT_ffffa8f1);
  fVar16 = (float)FUN_00002500(fVar18,uVar17,uVar3);
  fVar15 = rx8_absolute_difference(fVar16,fVar15);
  if (DAT_ffffa998 == '\x01') {
    uVar3 = 7;
  }
  else if (DAT_ffffaae0 == '\0') {
    uVar3 = 0;
  }
  else if (DAT_ffffa96c == '\x01') {
    uVar3 = 0x3c;
  }
  else if ((fVar15 <= fVar18) && (9 < DAT_ffffa8f0)) {
    uVar3 = (uint)DAT_ffffa8f1;
  }
  DAT_ffffa8f1 = FUN_0005d0b4(uVar3);
  return;
}



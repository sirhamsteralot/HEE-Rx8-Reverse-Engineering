/* ROM address: 0x0004deac; body bytes: 896; decompiled */

undefined1 * FUN_0004deac(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  
  bVar8 = DAT_ffffcf97;
  cVar7 = DAT_ffffcf96;
  cVar6 = DAT_ffffcf94;
  cVar5 = DAT_ffffcf93;
  cVar4 = DAT_ffffcf91;
  cVar3 = DAT_ffffcf90;
  cVar2 = DAT_ffffcf8e;
  cVar1 = DAT_ffffcf8d;
  fVar14 = DAT_ffffcf38 + 1.5;
  uVar18 = DAT_ffffbc1c;
  fVar10 = (float)FUN_00002068(DAT_ffffbc1c,&DAT_0006bf48);
  fVar15 = DAT_ffffcf40 + 1.5;
  fVar11 = (float)FUN_00002068(uVar18,&DAT_0006bf60);
  fVar16 = DAT_ffffcf48 + 1.5;
  fVar12 = (float)FUN_00002068(uVar18,&DAT_0006bf78);
  fVar17 = DAT_ffffcf50 + 1.5;
  fVar13 = (float)FUN_00002068(uVar18,&DAT_0006bf90);
  if (DAT_ffffcf70 == '\0') {
    DAT_ffffcf8d = '\0';
    DAT_ffffcf8e = '\0';
    DAT_ffffcf90 = '\0';
    DAT_ffffcf91 = '\0';
    DAT_ffffcf93 = '\0';
    DAT_ffffcf94 = '\0';
    DAT_ffffcf96 = '\0';
    DAT_ffffcf97 = 0;
  }
  else {
    if ((DAT_ffffcf8c != '\0') ||
       (((DAT_ffffcf8d != '\0' && (DAT_ffffcf8e != '\0')) && (fVar14 <= DAT_ffffcf30)))) {
      DAT_ffffcf8d = '>';
      DAT_ffffcf8e = '>';
    }
    else {
      if ((DAT_ffffcf30 <= DAT_ffffcf38) && (DAT_ffffcf8d != '\0')) {
        DAT_ffffcf8d = DAT_ffffcf8d + -1;
      }
      if ((DAT_ffffcf30 <= fVar10) && (DAT_ffffcf8e != '\0')) {
        DAT_ffffcf8e = DAT_ffffcf8e + -1;
      }
    }
    if ((DAT_ffffcf8f != '\0') ||
       (((DAT_ffffcf90 != '\0' && (DAT_ffffcf91 != '\0')) && (fVar15 <= DAT_ffffcf30)))) {
      DAT_ffffcf90 = '>';
      DAT_ffffcf91 = '>';
    }
    else {
      if ((DAT_ffffcf30 <= DAT_ffffcf40) && (DAT_ffffcf90 != '\0')) {
        DAT_ffffcf90 = DAT_ffffcf90 + -1;
      }
      if ((DAT_ffffcf30 <= fVar11) && (DAT_ffffcf91 != '\0')) {
        DAT_ffffcf91 = DAT_ffffcf91 + -1;
      }
    }
    if ((DAT_ffffcf92 != '\0') ||
       (((DAT_ffffcf93 != '\0' && (DAT_ffffcf94 != '\0')) && (fVar16 <= DAT_ffffcf30)))) {
      DAT_ffffcf93 = '>';
      DAT_ffffcf94 = '>';
    }
    else {
      if ((DAT_ffffcf30 <= DAT_ffffcf48) && (DAT_ffffcf93 != '\0')) {
        DAT_ffffcf93 = DAT_ffffcf93 + -1;
      }
      if ((DAT_ffffcf30 <= fVar12) && (DAT_ffffcf94 != '\0')) {
        DAT_ffffcf94 = DAT_ffffcf94 + -1;
      }
    }
    if ((DAT_ffffcf95 != '\0') ||
       (((DAT_ffffcf96 != '\0' && (DAT_ffffcf97 != 0)) && (fVar17 <= DAT_ffffcf30)))) {
      DAT_ffffcf96 = '>';
      DAT_ffffcf97 = 0x3e;
    }
    else {
      if ((DAT_ffffcf30 <= DAT_ffffcf50) && (DAT_ffffcf96 != '\0')) {
        DAT_ffffcf96 = DAT_ffffcf96 + -1;
      }
      if ((DAT_ffffcf30 <= fVar13) && (DAT_ffffcf97 != 0)) {
        DAT_ffffcf97 = DAT_ffffcf97 - 1;
      }
    }
  }
  if (((cVar1 != '\0') && (DAT_ffffcf8d == '\0')) || ((cVar2 != '\0' && (DAT_ffffcf8e == '\0')))) {
    DAT_ffffcf76 = 0;
  }
  if (((cVar3 != '\0') && (DAT_ffffcf90 == '\0')) || ((cVar4 != '\0' && (DAT_ffffcf91 == '\0')))) {
    DAT_ffffcf78 = 0;
  }
  if (((cVar5 != '\0') && (DAT_ffffcf93 == '\0')) || ((cVar6 != '\0' && (DAT_ffffcf94 == '\0')))) {
    DAT_ffffcf7a = 0;
  }
  if (((cVar7 != '\0') && (DAT_ffffcf96 == '\0')) ||
     ((puVar9 = (undefined1 *)(uint)bVar8, puVar9 != (undefined1 *)0x0 && (DAT_ffffcf97 == 0)))) {
    puVar9 = &DAT_ffffcf7c;
    DAT_ffffcf7c = 0;
  }
  return puVar9;
}



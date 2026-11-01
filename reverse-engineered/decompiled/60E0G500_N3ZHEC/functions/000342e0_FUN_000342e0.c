/* ROM address: 0x000342e0; body bytes: 498; decompiled */

undefined4 * FUN_000342e0(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  cVar4 = DAT_ffffcda0;
  cVar3 = DAT_ffffc102;
  cVar2 = DAT_ffffa415;
  fVar6 = DAT_ffffb5b8;
  DAT_ffffc0e8 = FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&LAB_0006b680);
  DAT_ffffc0ec = 0x400ccccd;
  DAT_ffffc0f0 = FUN_000020dc(DAT_ffffc12c,fVar6,&LAB_0006b69c);
  DAT_ffffc0f4 = 0x40133333;
  if ((cVar2 == '\0') || (cVar2 == '\f')) {
    DAT_ffffc0f8 = DAT_ffffc0e8;
    if (cVar4 == '\x01') {
      DAT_ffffc0f8 = DAT_ffffc0ec;
    }
  }
  else {
    DAT_ffffc0f8 = DAT_ffffc0f0;
    if (cVar4 == '\x01') {
      DAT_ffffc0f8 = 0x40133333;
    }
  }
  DAT_ffffa328 = DAT_ffffc0f8;
  if (cVar4 == '\0') {
    DAT_ffffc0fc = FUN_000020c4(fVar6,&DAT_0006b650);
    DAT_ffffc0fe = FUN_000020c4(fVar6,&DAT_0006b65c);
  }
  else {
    DAT_ffffc0fc = 0xf3;
    DAT_ffffc0fe = 0xe0;
  }
  FUN_0000c0f0((int)DAT_ffffc0fc,(int)DAT_ffffc0fe);
  fVar9 = DAT_ffffa764;
  fVar10 = DAT_ffffa760;
  fVar6 = rx8_absolute_difference(fVar6,DAT_ffffc0d8);
  fVar7 = rx8_absolute_difference(DAT_ffffc12c,DAT_ffffc0dc);
  fVar8 = rx8_absolute_difference(DAT_ffffadc0,DAT_ffffc0e0);
  if ((((DAT_ffffc110 == 0.0) && (fVar10 != 0.0)) || ((DAT_ffffc114 == 0.0 && (fVar9 != 0.0)))) ||
     (((60.0 <= fVar6 || (0.08 <= fVar7)) || (8.0 <= fVar8)))) {
    DAT_ffffc102 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffc102 = 0;
    bVar1 = false;
  }
  DAT_ffffc110 = fVar10;
  DAT_ffffc114 = fVar9;
  if (bVar1) {
    DAT_ffffc0c5 = '\x01';
  }
  else {
    if (cVar3 != '\0') {
      DAT_ffffc118 = 0x14;
    }
    if (DAT_ffffc118 == 0) {
      DAT_ffffc0c5 = '\0';
    }
    else {
      DAT_ffffc118 = DAT_ffffc118 + -1;
    }
  }
  if (DAT_ffffc0c5 == '\x01') {
    DAT_ffffc0cc = 0x3e400000;
    DAT_ffffc0d4 = 0x3dc00000;
    puVar5 = (undefined4 *)&UNK_00000001;
  }
  else {
    puVar5 = &DAT_ffffc0cc;
    DAT_ffffc0cc = 0x3d800000;
    DAT_ffffc0d4 = 0x3d000000;
  }
  DAT_ffffc0d0 = 0x3e004ea5;
  DAT_ffffc0e4 = DAT_ffffa324 != '\0';
  return puVar5;
}



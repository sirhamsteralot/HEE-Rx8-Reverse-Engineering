/* ROM address: 0x0000e560; body bytes: 672; decompiled */

undefined2 * FUN_0000e560(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined2 *extraout_r0;
  undefined2 *puVar4;
  undefined4 uVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  
  bVar3 = DAT_ffffbfa4;
  cVar2 = DAT_ffffb5aa;
  cVar1 = DAT_ffffb5a4;
  if ((DAT_ffffa4a1 == '\x01') && (DAT_ffffb5aa == '\0')) {
    DAT_ffffa48c = 0x58;
  }
  if (((DAT_ffffb5bc < 15.0) || (DAT_ffffb5b8 < 1500.0)) || (DAT_ffffa48c == 0)) {
    DAT_ffffa462 = '\x01';
  }
  else {
    DAT_ffffa462 = '\0';
  }
  if (DAT_ffffa48c != 0) {
    DAT_ffffa48c = DAT_ffffa48c + -1;
  }
  if (DAT_ffffb5a4 == '\x01') {
    DAT_ffffa461 = DAT_ffffbca9;
  }
  else if (DAT_ffffbcad == '\x01') {
    DAT_ffffa461 = '\x01';
  }
  else {
    DAT_ffffa461 = '\x02';
  }
  fVar6 = DAT_ffffb5bc;
  uVar7 = DAT_ffffaa10;
  fVar8 = DAT_ffffb5cc;
  fVar9 = DAT_ffffbc1c;
  uVar5 = FUN_000024c0(0x41000000,0,(int)DAT_ffffa424);
  DAT_ffffa468 = (float)FUN_00002068(uVar5,&DAT_000696ec);
  if (fVar9 < 120.0) {
    if (fVar9 < 115.0) {
      DAT_ffffa499 = '\0';
    }
  }
  else {
    DAT_ffffa499 = '\x01';
  }
  puVar4 = (undefined2 *)(uint)bVar3;
  DAT_ffffa458 = DAT_ffffa468;
  if (puVar4 == (undefined2 *)&UNK_00000001) {
    DAT_ffffa458 = DAT_ffffa468 + 0.0;
  }
  if (((fVar6 < -50.0) && (DAT_ffffa462 == '\x01')) && (cVar1 == '\x01')) {
    DAT_ffffa458 = DAT_ffffa458 + 0.0;
  }
  if (DAT_ffffcce1 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 5000.0;
  }
  if (DAT_ffffb340 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 10000.0;
  }
  if (DAT_ffffa7c8 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 1500.0;
  }
  if (DAT_ffffc600 == '\x01') {
    DAT_ffffa458 = DAT_ffffa458 + 10000.0;
  }
  if (((DAT_ffffbb38 == '\x01') && (DAT_ffffb5ac == '\0')) && (DAT_ffffa499 == '\x01')) {
    DAT_ffffa458 = DAT_ffffa458 + 1500.0;
  }
  if (cVar2 == '\x01') {
    DAT_ffffa46c = (float)FUN_00002068(uVar7,&DAT_00069724);
  }
  else {
    fVar6 = (float)FUN_00002500(0x3f800000,0,(int)DAT_ffffa461);
    DAT_ffffa46c = (float)FUN_000020dc(uVar7,fVar6,&DAT_0006974c);
  }
  DAT_ffffa448 = DAT_ffffa458 + DAT_ffffa46c;
  if (DAT_ffffaada == '\0') {
    DAT_ffffa454 = 300.0;
  }
  else if (fVar8 < DAT_ffffa448) {
    DAT_ffffa454 = 500.0;
  }
  fVar9 = 0.0;
  if (cVar2 == '\0') {
    DAT_ffffa480 = (float)FUN_000020dc(uVar7,fVar6,&DAT_00069768);
    fVar9 = DAT_ffffa480 + fVar9;
  }
  if (puVar4 == (undefined2 *)&UNK_00000001) {
    fVar9 = fVar9 + 0.0;
  }
  fVar6 = DAT_ffffa454 + fVar9;
  DAT_ffffa45c = fVar9;
  if (((DAT_ffffa448 <= fVar8) && (puVar4 = &DAT_0006d098, 0x5d < DAT_ffffa496)) &&
     (DAT_ffffb5aa == '\0')) {
    fVar6 = rx8_min_float(fVar6,200.0);
    puVar4 = extraout_r0;
  }
  DAT_ffffa44c = fVar6;
  if (fVar8 < DAT_ffffa448) {
    DAT_ffffa496 = 0;
  }
  else {
    puVar4 = (undefined2 *)FUN_00002460((int)(short)DAT_ffffa496,1);
    DAT_ffffa496 = (ushort)puVar4;
  }
  DAT_ffffa4a1 = cVar2;
  return puVar4;
}



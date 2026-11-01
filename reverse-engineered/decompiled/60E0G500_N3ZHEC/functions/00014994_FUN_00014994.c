/* ROM address: 0x00014994; body bytes: 516; decompiled */

undefined2 * FUN_00014994(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  float fVar7;
  
  cVar3 = DAT_ffffbdd5;
  bVar2 = DAT_ffffb5aa;
  cVar1 = DAT_ffffb5a4;
  if (DAT_ffffbc1c <= 4.0) {
    if (DAT_ffffbc1c <= 3.0) {
      DAT_ffffa837 = '\0';
    }
  }
  else {
    DAT_ffffa837 = '\x01';
  }
  if (DAT_ffffaa40 < 1.5) {
    if (DAT_ffffaa40 < 1.0) {
      DAT_ffffa831 = '\0';
    }
  }
  else {
    DAT_ffffa831 = '\x01';
  }
  if ((DAT_ffffa831 == '\x01') && (1 < DAT_ffffa830)) {
    DAT_ffffa7c6 = '\x01';
  }
  else if ((DAT_ffffa831 == '\0') && (0x3d < DAT_ffffa81a)) {
    DAT_ffffa7c6 = '\0';
  }
  fVar7 = DAT_ffffb5b8;
  if (DAT_ffffa831 == '\x01') {
    DAT_ffffa830 = FUN_00002478((int)(char)DAT_ffffa830,1);
    DAT_ffffa81a = 0;
  }
  else {
    DAT_ffffa830 = 0;
    DAT_ffffa81a = FUN_00002460((int)(short)DAT_ffffa81a,1);
  }
  uVar6 = 0x3727c5ac;
  if (((DAT_ffffa854 == '\0') || (DAT_ffffaada == '\0')) || ((cVar1 == '\x01' && (bVar2 == 0)))) {
    DAT_ffffa800 = 0x3e;
    DAT_ffffa7fc = fVar7;
  }
  else {
    if (DAT_ffffa800 != 0) {
      DAT_ffffa800 = DAT_ffffa800 + -1;
    }
    DAT_ffffa7fc = rx8_first_order_filter(fVar7,DAT_ffffa7fc,0.08,1e-05);
  }
  if ((cVar3 == '\0') && (DAT_ffffa832 == '\x01')) {
    DAT_ffffa7c4 = 0;
    puVar5 = (undefined2 *)0x1;
  }
  else {
    puVar4 = (undefined2 *)FUN_00002440(DAT_ffffa8b4,0,uVar6);
    puVar5 = puVar4;
    if (((((DAT_ffffb5e8 != '\0') ||
          (((puVar5 = &DAT_ffffa424, DAT_ffffa424 < 0x7d || (DAT_ffffa837 != '\0')) ||
           (DAT_ffffa7c6 != '\0')))) ||
         ((cVar1 != '\0' && (puVar5 = (undefined2 *)(uint)bVar2, puVar5 != (undefined2 *)0x1)))) ||
        (((((uint)puVar4 & 0xff) != 0 || ((150.0 < DAT_ffffa7fc - fVar7 || (DAT_ffffa800 != 0)))) &&
         (DAT_ffffa7bc < fVar7)))) ||
       ((((DAT_ffffc656 != '\0' ||
          (puVar5 = (undefined2 *)(int)DAT_ffffc64b, puVar5 != (undefined2 *)0x0)) ||
         (puVar5 = (undefined2 *)&DAT_ffffc600, DAT_ffffc600 != '\0')) || (DAT_ffffc68e != '\0'))))
    {
      DAT_ffffa7c4 = 0;
    }
    else {
      DAT_ffffa7c4 = 1;
    }
  }
  DAT_ffffa832 = cVar3;
  return puVar5;
}



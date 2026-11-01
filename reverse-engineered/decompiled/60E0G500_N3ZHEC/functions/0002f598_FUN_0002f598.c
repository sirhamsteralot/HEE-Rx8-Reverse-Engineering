/* ROM address: 0x0002f598; body bytes: 320; decompiled */

undefined * FUN_0002f598(void)

{
  byte bVar1;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  bVar1 = DAT_ffffa42c;
  fVar4 = 7300.0;
  fVar3 = 115.5;
  fVar5 = DAT_ffffaa10;
  fVar6 = DAT_ffffb5b8;
  DAT_ffffbdf4 = FUN_000020c4(DAT_ffffaa10,&DAT_0006ae58);
  if (fVar6 < 600.0) {
    if (fVar6 < 400.0) {
      DAT_ffffbe02 = 0;
    }
  }
  else {
    DAT_ffffbe02 = 1;
  }
  if (fVar6 < 7800.0) {
    if (fVar6 < fVar4) {
      DAT_ffffbe03 = '\0';
    }
  }
  else {
    DAT_ffffbe03 = '\x01';
  }
  if (fVar5 < 118.0) {
    if (fVar5 < fVar3) {
      DAT_ffffbe04 = '\0';
    }
  }
  else {
    DAT_ffffbe04 = '\x01';
  }
  puVar2 = (undefined *)(uint)DAT_ffffbfa4;
  if ((((((puVar2 == &UNK_00000001) &&
         (puVar2 = (undefined *)(int)DAT_ffffbdf4, puVar2 <= (undefined *)(int)DAT_ffffa424)) &&
        (puVar2 = (undefined *)(uint)bVar1, puVar2 == (undefined *)0x0)) &&
       ((puVar2 = &DAT_ffffbdfe, 2 < DAT_ffffbdfe &&
        (puVar2 = (undefined *)(uint)DAT_ffffbe02, puVar2 == &UNK_00000001)))) &&
      ((puVar2 = (undefined *)(int)DAT_ffffbe03, puVar2 == (undefined *)0x0 &&
       ((puVar2 = &DAT_ffffbe04, DAT_ffffbe04 == '\0' && (DAT_ffffc656 == '\0')))))) &&
     ((DAT_ffffbdde == '\0' &&
      ((DAT_ffffbddf == '\0' && (puVar2 = (undefined *)(uint)DAT_ffffbde2, puVar2 == &UNK_00000001))
      )))) {
    DAT_ffffbdd5 = 1;
  }
  else {
    DAT_ffffbdd5 = 0;
  }
  if (bVar1 == 0) {
    puVar2 = (undefined *)FUN_00002478((int)(char)DAT_ffffbdfe,1);
    DAT_ffffbdfe = (byte)puVar2;
  }
  else {
    DAT_ffffbdfe = 0;
  }
  return puVar2;
}



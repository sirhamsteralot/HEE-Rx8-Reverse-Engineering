/* ROM address: 0x00043a4c; body bytes: 212; decompiled */

undefined * FUN_00043a4c(void)

{
  char cVar1;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  cVar1 = DAT_ffffaada;
  fVar4 = DAT_ffffaa40;
  fVar5 = DAT_ffffb5b8;
  fVar3 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006bbf0);
  puVar2 = &UNK_00000001;
  if ((cVar1 == '\x01') || (puVar2 = &DAT_0007b3d9, DAT_ffffcaaf == 'd')) {
    DAT_ffffcab6 = 0;
    DAT_ffffcab8 = 0;
    DAT_ffffcab9 = 0;
  }
  else {
    if (((DAT_ffffcb09 == 1) || ((DAT_ffffcb04 < fVar3 && (fVar3 <= fVar4)))) && (DAT_ffffcab7 == 1)
       ) {
      DAT_ffffcab6 = 1;
    }
    puVar2 = (undefined *)(uint)DAT_ffffcb09;
    if ((puVar2 == &UNK_00000001) &&
       (puVar2 = (undefined *)(uint)DAT_ffffcab7, puVar2 == &UNK_00000001)) {
      DAT_ffffcab8 = 1;
    }
    if ((DAT_ffffcab0 != '\0') &&
       (puVar2 = (undefined *)(uint)DAT_ffffcab6, puVar2 == &UNK_00000001)) {
      DAT_ffffcab9 = 1;
    }
  }
  if (DAT_ffffcaaf == '\0') {
    if (3200.0 < fVar5) {
      DAT_ffffcaba = 1;
    }
    else {
      DAT_ffffcaba = 0;
    }
  }
  DAT_ffffcb04 = fVar4;
  DAT_ffffcb09 = cVar1;
  return puVar2;
}



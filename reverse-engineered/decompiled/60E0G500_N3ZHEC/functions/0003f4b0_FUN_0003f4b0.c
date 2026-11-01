/* ROM address: 0x0003f4b0; body bytes: 358; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003f634) */

void FUN_0003f4b0(void)

{
  char cVar1;
  float *pfVar2;
  undefined *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (DAT_ffffb13a == '\x01') {
    DAT_ffffc70c = '\0';
  }
  else if (DAT_ffffc70c != '\0') {
    DAT_ffffc70c = DAT_ffffc70c + -1;
  }
  if (DAT_ffffc6b0 <= DAT_ffffc6b4) {
    puVar3 = &DAT_0006bb34;
  }
  else {
    puVar3 = &DAT_0006bb20;
  }
  fVar5 = DAT_ffffc5a8;
  fVar6 = DAT_ffffaae4;
  fVar4 = DAT_ffffb190;
  DAT_ffffc6e8 = FUN_00002068(DAT_ffffaa88,puVar3);
  if (DAT_ffffc6bf == '\x01') {
    DAT_ffffc6ec = 0x3f800000;
  }
  else {
    DAT_ffffc6ec = FUN_00002068(DAT_ffffaa10,&DAT_0006bb48);
  }
  DAT_ffffc6f0 = (DAT_ffffa6ac + DAT_ffffa760 + DAT_ffffa670 + DAT_ffffc6c4) * 2.25;
  cVar1 = FUN_00002440(fVar4,0,0x3727c5ac);
  if ((cVar1 == '\0') || (0.0 < fVar4)) {
    if (cVar1 == '\0') {
      fVar4 = 8.5;
    }
    else {
      fVar4 = 6.5;
    }
    DAT_ffffc6f4 = DAT_ffffc6f0 + fVar6 * fVar4 * 14.7 + DAT_ffffc6dc;
  }
  if ((DAT_ffffa428 == '\0') && (DAT_ffffa41c == '\0')) {
    FUN_0003ec20(DAT_ffffc6b4,&DAT_ffff8738);
  }
  if (DAT_ffffbfd4 == '\x01') {
    DAT_ffffc6f8 = (float)FUN_00002068(fVar6,&DAT_0006bae4);
    if (DAT_ffffc6bf == '\x01') {
      pfVar2 = (float *)&DAT_0007aef4;
    }
    else {
      pfVar2 = (float *)&DAT_0007aef8;
    }
    DAT_ffffc6fc = *pfVar2 * DAT_ffffc6f8 * fVar5;
  }
  else {
    DAT_ffffc6f8 = 1.0;
    DAT_ffffc6fc = 1.0;
  }
  FUN_0003f8d0();
  return;
}



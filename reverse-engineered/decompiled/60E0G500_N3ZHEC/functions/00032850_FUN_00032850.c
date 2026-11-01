/* ROM address: 0x00032850; body bytes: 504; decompiled */

void FUN_00032850(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 local_28;
  char cStack_24;
  char cStack_20;
  
  cStack_24 = DAT_ffffbff5;
  cStack_20 = DAT_ffffbff6;
  if (DAT_ffffb5b8 < 200.0) {
    if (DAT_ffffb5b8 < 150.0) {
      DAT_ffffc001 = '\0';
    }
  }
  else {
    DAT_ffffc001 = '\x01';
  }
  if ((DAT_ffffbff6 == '\0') && (0x32 < DAT_ffffbffa)) {
    DAT_ffffbff5 = '\0';
  }
  else if ((DAT_ffffaae0 == '\0') && (DAT_ffffc001 == '\0')) {
    DAT_ffffbff5 = '\x01';
  }
  fVar2 = DAT_ffffaa88;
  fVar3 = DAT_ffffaa10;
  fVar4 = DAT_ffffb5b8;
  if (((DAT_ffffbff5 == '\x01') && (DAT_ffffcd06 == '\0')) && (DAT_ffffa96a == '\0')) {
    DAT_ffffbff6 = DAT_ffffbff8 < 0x32;
    DAT_ffffbff8 = FUN_00002460((int)(short)DAT_ffffbff8,1);
  }
  else {
    DAT_ffffbff6 = '\0';
    DAT_ffffbff8 = 0;
  }
  cVar1 = cStack_24;
  if ((cStack_20 == '\x01') && (DAT_ffffbff6 == '\0')) {
    DAT_ffffbffa = 0;
    DAT_ffffc002 = '\x01';
  }
  else if ((DAT_ffffc002 == '\x01') && (DAT_ffffbffa != 0xffff)) {
    DAT_ffffbffa = DAT_ffffbffa + 1;
  }
  if ((cStack_24 == '\0') && (DAT_ffffbff5 == '\x01')) {
    local_28 = 0;
    FUN_00009630(0,2,&local_28);
  }
  if ((cVar1 == '\x01') && (DAT_ffffbff5 == '\0')) {
    local_28 = 0;
    FUN_00009630(0,3,&local_28);
  }
  if (fVar4 < 6100.0) {
    if (fVar4 < 5912.5) {
      DAT_ffffbffc = '\0';
    }
  }
  else {
    DAT_ffffbffc = '\x01';
  }
  if (fVar3 < 20.0) {
    if (fVar3 < 18.12) {
      DAT_ffffbffd = '\0';
    }
  }
  else {
    DAT_ffffbffd = '\x01';
  }
  if (fVar2 < 0.0) {
    if (fVar2 < -0.25) {
      DAT_ffffbffe = '\0';
    }
  }
  else {
    DAT_ffffbffe = '\x01';
  }
  if ((((DAT_ffffbffc == '\x01') && (DAT_ffffbffd == '\x01')) && (DAT_ffffbffe == '\x01')) ||
     (DAT_ffffbff6 == '\x01')) {
    DAT_ffffbff4 = '\x01';
  }
  else {
    DAT_ffffbff4 = '\0';
  }
  DAT_ffffbfff = DAT_ffffbff4 == '\0';
  DAT_ffffbff3 = FUN_0005d7fc(DAT_ffffbfff);
  return;
}



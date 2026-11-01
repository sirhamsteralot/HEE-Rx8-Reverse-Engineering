/* ROM address: 0x0002ca34; body bytes: 576; decompiled */

char FUN_0002ca34(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  float fVar5;
  
  cVar2 = DAT_ffffbd58;
  cVar1 = DAT_ffffaae0;
  if (0.125 <= DAT_ffffbc9c) {
    if (1.0 <= DAT_ffffbc9c) {
      if (2.0 <= DAT_ffffbc9c) {
        if (3.0 <= DAT_ffffbc9c) {
          DAT_ffffbca3 = '\x05';
        }
        else {
          DAT_ffffbca3 = '\x04';
        }
      }
      else {
        DAT_ffffbca3 = '\x03';
      }
    }
    else {
      DAT_ffffbca3 = '\x02';
    }
  }
  else {
    DAT_ffffbca3 = '\x01';
  }
  fVar5 = DAT_ffffc008;
  if ((((DAT_ffffaae0 == '\x01') && (DAT_ffffbca6 == '\0')) && (DAT_ffffbdb5 == '\x01')) ||
     (DAT_ffffbdb4 == '\0')) {
    FUN_0003ebc0(&DAT_ffff868c,0);
  }
  else if (((DAT_ffffbca3 == '\x01') && (DAT_ffffbca4 == '\x01')) && (DAT_ffffbca5 != '\x01')) {
    uVar3 = FUN_0003eaa4(&DAT_ffff868c,0);
    FUN_0003ebc0(&DAT_ffff868c,uVar3 ^ 1);
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
  if (((cVar4 == '\0') || (fVar5 < 22.5)) || ((DAT_ffffbca3 != '\x02' && (DAT_ffffbca4 != '\x02'))))
  {
    DAT_ffffbca0 = 0;
  }
  else {
    cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
    if (((cVar4 == '\x01') && (DAT_ffffbca3 == '\x02')) && (DAT_ffffbca4 == '\x02')) {
      DAT_ffffbca0 = 1;
    }
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
  if (((cVar4 == '\0') || (fVar5 < 22.5)) || ((DAT_ffffbca3 != '\x03' && (DAT_ffffbca4 != '\x03'))))
  {
    DAT_ffffbca1 = 0;
  }
  else {
    cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
    if (((cVar4 == '\x01') && (DAT_ffffbca3 == '\x03')) &&
       ((DAT_ffffbca4 == '\x03' && ((DAT_ffffbca5 != '\x03' && (cVar2 == '\x01')))))) {
      DAT_ffffbca1 = 1;
    }
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
  if (((cVar4 == '\0') || (fVar5 < 22.5)) ||
     ((DAT_ffffbca3 != '\x04' && (cVar4 = DAT_ffffbca4, DAT_ffffbca4 != '\x04')))) {
    DAT_ffffbca2 = 0;
  }
  else {
    cVar4 = FUN_0003eaa4(&DAT_ffff868c,0);
    if ((((cVar4 == '\x01') && (cVar4 = DAT_ffffbca3, DAT_ffffbca3 == '\x04')) &&
        (cVar4 = DAT_ffffbca4, DAT_ffffbca4 == '\x04')) &&
       ((cVar4 = DAT_ffffbca5, DAT_ffffbca5 != '\x04' && (cVar4 = cVar2, cVar2 == '\x01')))) {
      DAT_ffffbca2 = 1;
    }
  }
  DAT_ffffbca5 = DAT_ffffbca4;
  DAT_ffffbca4 = DAT_ffffbca3;
  DAT_ffffbca6 = cVar1;
  return cVar4;
}



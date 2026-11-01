/* ROM address: 0x00025750; body bytes: 630; decompiled */

char FUN_00025750(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = DAT_ffffbb54;
  cVar2 = DAT_ffffb5af;
  cVar4 = DAT_ffffb5ad;
  if (DAT_ffffb5a4 == '\x01') {
    cVar4 = '\x01';
    if ((DAT_ffffb5ab == '\x01') || (cVar4 = DAT_ffffc004, DAT_ffffc004 == '\x01')) {
      DAT_ffffb5aa = 1;
    }
    else {
      DAT_ffffb5aa = 0;
    }
    DAT_ffffb5ac = 0;
    DAT_ffffb5ae = 0;
    DAT_ffffb5b0 = 0;
    return cVar4;
  }
  bVar1 = DAT_ffffbb54 == '\a';
  if (bVar1 == (bool)DAT_ffffb5af) {
    DAT_ffffb5af = bVar1;
    if (DAT_ffffb5b4 == '\x01') {
      DAT_ffffb5b2 = FUN_00002478((int)(char)DAT_ffffb5b2,1);
    }
  }
  else {
    DAT_ffffb5b2 = 0;
    DAT_ffffb5b4 = '\x01';
    DAT_ffffb5af = bVar1;
  }
  if (cVar3 == '\0') {
    DAT_ffffb5aa = 1;
  }
  else {
    DAT_ffffb5aa = 0;
    if (cVar3 != '\a') {
      DAT_ffffb5ad = '\x01';
      goto LAB_00025836;
    }
  }
  DAT_ffffb5ad = '\0';
LAB_00025836:
  if (DAT_ffffb5ad == cVar4) {
    if (DAT_ffffb5b3 == '\x01') {
      DAT_ffffb5b1 = FUN_00002478((int)(char)DAT_ffffb5b1,1);
    }
  }
  else {
    DAT_ffffb5b1 = 0;
    DAT_ffffb5b3 = '\x01';
  }
  if ((cVar4 == '\x01') && (DAT_ffffb5ad == '\0')) {
    DAT_ffffb5a8 = '\x03';
  }
  else if (DAT_ffffb5af == '\x01') {
    DAT_ffffb5a8 = '\0';
  }
  else if (DAT_ffffb5a8 != '\0') {
    DAT_ffffb5a8 = DAT_ffffb5a8 + -1;
  }
  if (DAT_ffffb5af == '\0') {
    if (cVar2 == '\x01') {
      DAT_ffffb5a9 = '\x16';
    }
    else if (DAT_ffffb5a9 != '\0') {
      DAT_ffffb5a9 = DAT_ffffb5a9 + -1;
    }
  }
  else {
    DAT_ffffb5a9 = '\0';
  }
  if (DAT_ffffb5ad == '\x01') {
    if ((DAT_ffffb5a8 == '\0') && (DAT_ffffb5a9 == '\0')) {
      if (20.0 < DAT_ffffbc1c) {
        if (0x5d < DAT_ffffb5b1) {
          DAT_ffffb5b0 = '\x01';
        }
      }
      else if (9 < DAT_ffffb5b1) {
        DAT_ffffb5b0 = '\x01';
      }
    }
    if ((DAT_ffffa7c8 == '\x01') && (2000.0 < DAT_ffffb5b8)) {
      DAT_ffffb5b0 = '\x01';
    }
  }
  else if (0xb < DAT_ffffb5b1) {
    DAT_ffffb5b0 = '\0';
  }
  if ((DAT_ffffb5b0 == '\x01') || ((DAT_ffffb5af == '\0' && (2 < DAT_ffffb5b2)))) {
    DAT_ffffb5ae = '\0';
  }
  else if ((DAT_ffffb5af == '\x01') &&
          ((5 < DAT_ffffb5b2 || ((DAT_ffffa7c8 == '\x01' && (2000.0 < DAT_ffffb5b8)))))) {
    DAT_ffffb5ae = '\x01';
  }
  cVar4 = '\x01';
  if ((DAT_ffffb5b0 == '\x01') || (cVar4 = DAT_ffffb5ae, DAT_ffffb5ae == '\x01')) {
    DAT_ffffb5ac = 1;
  }
  else {
    DAT_ffffb5ac = 0;
  }
  return cVar4;
}



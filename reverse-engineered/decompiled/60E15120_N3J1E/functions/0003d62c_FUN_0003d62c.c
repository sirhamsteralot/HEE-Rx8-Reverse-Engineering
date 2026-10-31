/* ROM address: 0x0003d62c; body bytes: 240; decompiled */

char FUN_0003d62c(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = DAT_ffffc625;
  cVar1 = DAT_ffffbf9c;
  if (DAT_ffffc610 == '\0') {
    DAT_ffffc625 = '\0';
  }
  else if (30.08 < vehicle_speed_ffffbbb4) {
    DAT_ffffc625 = '\x01';
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc626 = '\0';
    DAT_ffffc621 = '\n';
    DAT_ffffc628 = 0;
    DAT_ffffc629 = 0;
    cVar3 = '\x01';
  }
  else {
    if (DAT_ffffc627 != DAT_ffffbf9c) {
      DAT_ffffc626 = '\x01';
    }
    if (DAT_ffffc626 == '\x01') {
      DAT_ffffc621 = '\n';
      cVar3 = DAT_ffffb534;
      if (DAT_ffffb534 == '\x01') {
        cVar3 = ref_getFaultStatus__(0x4b);
        if (cVar3 == '\0') {
          DAT_ffffc629 = 1;
          DAT_ffffc628 = 0;
        }
      }
    }
    else {
      cVar3 = DAT_ffffc626;
      if ((DAT_ffffc625 == '\0') && (cVar3 = cVar2, cVar2 == '\x01')) {
        if (DAT_ffffc621 != '\0') {
          DAT_ffffc621 = DAT_ffffc621 + -1;
        }
        cVar3 = DAT_ffffb534;
        if (DAT_ffffb534 == '\x01') {
          cVar3 = ref_getFaultStatus__(0x4b);
          if ((cVar3 == '\0') && (DAT_ffffc621 == '\0')) {
            DAT_ffffc628 = 1;
            DAT_ffffc629 = 0;
          }
        }
      }
    }
  }
  DAT_ffffc627 = cVar1;
  return cVar3;
}



/* ROM address: 0x0002ba0c; body bytes: 298; decompiled */

uint FUN_0002ba0c(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = DAT_ffffa428;
  if (DAT_ffffbc1c <= 3.0) {
    if (DAT_ffffbc1c <= 1.0) {
      DAT_ffffbc07 = '\0';
    }
  }
  else {
    DAT_ffffbc07 = '\x01';
  }
  uVar2 = (uint)DAT_ffffaae0;
  if (DAT_ffffbc74 == '\x01') {
    if (DAT_ffffc68e == '\0') {
      if ((uVar2 == 1) &&
         (((DAT_ffffbc07 == '\0' && (0x1e < DAT_ffffbbfa)) ||
          ((DAT_ffffbc07 == '\x01' && (0x3a8 < DAT_ffffbbfa)))))) {
        DAT_ffffbbd9 = '\x01';
      }
    }
    else if (0x57d < DAT_ffffbbfa) {
      DAT_ffffbbd9 = '\x01';
    }
  }
  else {
    DAT_ffffbbd9 = '\0';
  }
  if ((uVar2 == 1) &&
     (((DAT_ffffa428 == '\0' && (DAT_ffffbbfc < 0x1f)) || (DAT_ffffbbd9 == '\x01')))) {
    DAT_ffffbbcf = 1;
  }
  else {
    DAT_ffffbbcf = 0;
  }
  if (DAT_ffffbc74 == '\x01') {
    DAT_ffffbbfa = FUN_00002460((int)(short)DAT_ffffbbfa,1);
  }
  else {
    DAT_ffffbbfa = 0;
  }
  if ((uVar2 == 1) && (cVar1 == '\0')) {
    uVar2 = FUN_00002460((int)(short)DAT_ffffbbfc,1);
    DAT_ffffbbfc = (ushort)uVar2;
  }
  else {
    DAT_ffffbbfc = 0;
  }
  return uVar2;
}



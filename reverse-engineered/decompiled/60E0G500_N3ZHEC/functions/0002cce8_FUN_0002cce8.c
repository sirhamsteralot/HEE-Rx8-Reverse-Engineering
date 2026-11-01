/* ROM address: 0x0002cce8; body bytes: 102; decompiled */

char FUN_0002cce8(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (DAT_ffffc68e != '\x01') {
    if (DAT_ffffb5a4 != '\x01') {
      DAT_ffffbcaa = 0;
      DAT_ffffbcab = 0;
      DAT_ffffbcac = 0;
      return DAT_ffffb5a4;
    }
    cVar1 = DAT_ffffbca8;
    if ((DAT_ffffbca8 != '\x01') && (DAT_ffffbca8 != '\x02')) {
      if ((DAT_ffffbca8 != '\x03') && (DAT_ffffbca8 != '\x04')) {
        if ((DAT_ffffbca8 != '\x05') && (DAT_ffffbca8 != '\x06')) {
          DAT_ffffbcaa = 0;
          DAT_ffffbcab = 0;
          DAT_ffffbcac = 0;
          return DAT_ffffbca8;
        }
        DAT_ffffbcaa = 0;
        DAT_ffffbcab = 0;
        DAT_ffffbcac = 1;
        return DAT_ffffbca8;
      }
      DAT_ffffbcaa = 0;
      DAT_ffffbcab = 1;
      DAT_ffffbcac = 0;
      return DAT_ffffbca8;
    }
  }
  DAT_ffffbcaa = 1;
  DAT_ffffbcab = 0;
  DAT_ffffbcac = 0;
  return cVar1;
}



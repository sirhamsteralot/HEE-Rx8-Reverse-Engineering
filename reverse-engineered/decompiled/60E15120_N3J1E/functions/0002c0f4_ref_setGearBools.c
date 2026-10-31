/* ROM address: 0x0002c0f4; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c8ac (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_setGearBools(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (DAT_ffffc61e != '\x01') {
    if (DAT_ffffb534 != '\x01') {
      DAT_ffffbc3e = 0;
      DAT_ffffbc3f = 0;
      DAT_ffffbc40 = 0;
      return DAT_ffffb534;
    }
    cVar1 = DAT_ffffbc3c;
    if ((DAT_ffffbc3c != '\x01') && (DAT_ffffbc3c != '\x02')) {
      if ((DAT_ffffbc3c != '\x03') && (DAT_ffffbc3c != '\x04')) {
        if ((DAT_ffffbc3c != '\x05') && (DAT_ffffbc3c != '\x06')) {
          DAT_ffffbc3e = 0;
          DAT_ffffbc3f = 0;
          DAT_ffffbc40 = 0;
          return DAT_ffffbc3c;
        }
        DAT_ffffbc3e = 0;
        DAT_ffffbc3f = 0;
        DAT_ffffbc40 = 1;
        return DAT_ffffbc3c;
      }
      DAT_ffffbc3e = 0;
      DAT_ffffbc3f = 1;
      DAT_ffffbc40 = 0;
      return DAT_ffffbc3c;
    }
  }
  DAT_ffffbc3e = 1;
  DAT_ffffbc3f = 0;
  DAT_ffffbc40 = 0;
  return cVar1;
}



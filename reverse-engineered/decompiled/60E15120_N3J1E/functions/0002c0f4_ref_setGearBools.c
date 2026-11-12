/* ROM address: 0x0002c0f4; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c8ac (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_setGearBools(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (DAT_ffffc61e != '\x01') {
    if (automatic_transmission_ffffb534 != '\x01') {
      DAT_ffffbc3e = 0;
      DAT_ffffbc3f = 0;
      DAT_ffffbc40 = 0;
      return automatic_transmission_ffffb534;
    }
    cVar1 = candidate_gear_ffffbc3c;
    if ((candidate_gear_ffffbc3c != '\x01') && (candidate_gear_ffffbc3c != '\x02')) {
      if ((candidate_gear_ffffbc3c != '\x03') && (candidate_gear_ffffbc3c != '\x04')) {
        if ((candidate_gear_ffffbc3c != '\x05') && (candidate_gear_ffffbc3c != '\x06')) {
          DAT_ffffbc3e = 0;
          DAT_ffffbc3f = 0;
          DAT_ffffbc40 = 0;
          return candidate_gear_ffffbc3c;
        }
        DAT_ffffbc3e = 0;
        DAT_ffffbc3f = 0;
        DAT_ffffbc40 = 1;
        return candidate_gear_ffffbc3c;
      }
      DAT_ffffbc3e = 0;
      DAT_ffffbc3f = 1;
      DAT_ffffbc40 = 0;
      return candidate_gear_ffffbc3c;
    }
  }
  DAT_ffffbc3e = 1;
  DAT_ffffbc3f = 0;
  DAT_ffffbc40 = 0;
  return cVar1;
}



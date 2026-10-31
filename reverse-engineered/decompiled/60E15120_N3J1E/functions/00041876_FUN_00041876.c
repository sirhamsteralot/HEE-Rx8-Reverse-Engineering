/* ROM address: 0x00041876; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000410aa (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00041876(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc91d = 0;
    DAT_ffffc91c = 0;
    DAT_ffffc922 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc91e;
    if (uVar1 == 1) {
      if (DAT_ffffaa78 <= 44.0) {
        if (0x9b < DAT_ffffc924) {
          DAT_ffffc91c = 1;
        }
        uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffc924,1);
        DAT_ffffc922 = 0;
        DAT_ffffc924 = (short)uVar1;
        return uVar1;
      }
      if (0x9b < DAT_ffffc922) {
        DAT_ffffc91d = 1;
      }
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffc922,1);
      DAT_ffffc922 = (ushort)uVar1;
    }
    else {
      DAT_ffffc922 = 0;
    }
  }
  DAT_ffffc924 = 0;
  return uVar1;
}



/* [ADDITIONAL SOURCE REVIEW]
 * misfire_persistence_count [medium]: If DAT_ffffb6ad==1: clears b6ab/b6a8/b6ad; else b6a8 = saturate(b6a8+1, 0xff) (0x2460) and b6ab = (b6a8 != 0). Called from 0x287aa.
 */
/* ROM address: 0x00026d04; body bytes: 88; decompiled */

uint candidate_misfire_persistence_count(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffb6ad;
  if (uVar1 == 1) {
    DAT_ffffb6ab = 0;
    DAT_ffffb6a8 = 0;
    DAT_ffffb6ad = 0;
  }
  else {
    if (DAT_ffffb6a8 < 0xff) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffb6a8,1);
      DAT_ffffb6a8 = (ushort)uVar1;
    }
    else {
      DAT_ffffb6a8 = 0xff;
    }
    if (DAT_ffffb6a8 == 0) {
      DAT_ffffb6ab = 0;
    }
    else {
      DAT_ffffb6ab = 1;
    }
  }
  return uVar1;
}



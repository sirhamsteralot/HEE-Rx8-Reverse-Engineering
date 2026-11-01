/* ROM address: 0x000457d4; body bytes: 158; decompiled */

uint FUN_000457d4(void)

{
  uint in_r7;
  uint unaff_r12;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcbe8 = 0;
    DAT_ffffcbea = 0;
  }
  if ((DAT_ffffb6d0 & 1) == 0) {
    in_r7 = (uint)DAT_ffffba93;
    unaff_r12 = 1;
  }
  else if ((DAT_ffffb6d0 & 1) == 1) {
    unaff_r12 = 0;
    in_r7 = (uint)DAT_ffffba92;
  }
  in_r7 = in_r7 & 0xff;
  if (in_r7 == 1) {
    if ((DAT_ffffcc00 * DAT_ffffbabc < DAT_ffffbac0) || (DAT_ffffcc04 * DAT_ffffbabc < DAT_ffffbab8)
       ) {
      in_r7 = unaff_r12 & 0xffff;
      (&DAT_ffffba92)[in_r7] = 0;
    }
    else if (DAT_ffffd201 == '\0') {
      DAT_ffffcbe8 = FUN_00002460((int)DAT_ffffcbe8,1);
      in_r7 = FUN_00002460((int)DAT_ffffcbea,1);
      DAT_ffffcbea = (short)in_r7;
    }
  }
  return in_r7;
}



/* ROM address: 0x0004489c; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000440b8 (158 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004489c(void)

{
  uint in_r7;
  uint unaff_r12;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb7c = 0;
    DAT_ffffcb7e = 0;
  }
  if ((DAT_ffffb660 & 1) == 0) {
    in_r7 = (uint)DAT_ffffba27;
    unaff_r12 = 1;
  }
  else if ((DAT_ffffb660 & 1) == 1) {
    unaff_r12 = 0;
    in_r7 = (uint)DAT_ffffba26;
  }
  in_r7 = in_r7 & 0xff;
  if (in_r7 == 1) {
    if ((DAT_ffffcb94 * DAT_ffffba54 < DAT_ffffba58) || (DAT_ffffcb98 * DAT_ffffba54 < DAT_ffffba50)
       ) {
      in_r7 = unaff_r12 & 0xffff;
      (&DAT_ffffba26)[in_r7] = 0;
    }
    else if (DAT_ffffd1c5 == '\0') {
      DAT_ffffcb7c = rx8_add_u16_saturate((int)DAT_ffffcb7c,1);
      in_r7 = rx8_add_u16_saturate((int)DAT_ffffcb7e,1);
      DAT_ffffcb7e = (short)in_r7;
    }
  }
  return in_r7;
}



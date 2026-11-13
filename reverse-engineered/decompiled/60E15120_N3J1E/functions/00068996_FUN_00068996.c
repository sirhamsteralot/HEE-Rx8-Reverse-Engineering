/* ROM address: 0x00068996; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067286 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068996(void)

{
  FUN_00068c58(4);
  DAT_ffffdde4 = rx8_add_u8_saturate((int)(char)DAT_ffffdde4,1);
  DAT_ffffddde = DAT_ffffddde + 7;
  if (DAT_ffffdddc <= DAT_ffffddde) {
    FUN_00068910();
    jump_to_FUN_00054a36((int)DAT_ffffdde0);
    return;
  }
  if ((DAT_ffffddf1 != 0) && (DAT_ffffddf1 <= DAT_ffffdde4)) {
    DAT_ffffdde4 = 0;
    DAT_ffffdde1 = 7;
    FUN_00068bc6(4,0x4b);
    return;
  }
  DAT_ffffdde1 = 9;
  FUN_00068bc6(2,DAT_ffffddf2);
  return;
}



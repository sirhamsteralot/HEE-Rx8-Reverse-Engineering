/* ROM address: 0x00068620; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066f10 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068620(void)

{
  FUN_00068c58(5);
  DAT_ffffdde8 = DAT_ffffdde8 + 7;
  DAT_ffffddee = rx8_add_u8_saturate((int)DAT_ffffddee,1);
  DAT_ffffddeb = 4;
  FUN_00068bc6(5,0x96);
  ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddc9,7);
  return;
}



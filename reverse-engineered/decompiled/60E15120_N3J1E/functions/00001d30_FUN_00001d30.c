/* ROM address: 0x00001d30; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001d30 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001d30(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x37;
  DAT_ffffdfc8 = 2;
  if ((DAT_ffffdfb0 == '\0') || (DAT_ffffdfb4._0_1_ == '\0')) {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 0) {
    DAT_ffffdfb4._0_1_ = '\0';
    DAT_ffffdfb4._1_1_ = 0;
    DAT_ffffdfcb = 0x79;
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}



/* ROM address: 0x00001774; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001774 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001774(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x85;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\x01') {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 1) {
    if ((*(char *)(param_1 + 4) == '\x01') || (*(char *)(param_1 + 4) == '\x02')) {
      DAT_ffffdfc6 = 0xc5;
      DAT_ffffdfca = *(undefined1 *)(param_1 + 4);
      DAT_ffffdfc8 = 1;
    }
    else {
      DAT_ffffdfcb = 0x12;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}



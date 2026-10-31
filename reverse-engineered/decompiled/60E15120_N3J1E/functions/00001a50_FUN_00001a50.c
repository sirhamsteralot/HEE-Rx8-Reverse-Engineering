/* ROM address: 0x00001a50; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001a50 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001a50(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x22;
  DAT_ffffdfc8 = 2;
  if (*(short *)(param_1 + 2) == 2) {
    if ((*(char *)(param_1 + 4) == -0x2f) && (*(char *)(param_1 + 5) == '\0')) {
      DAT_ffffdfc6 = 0x62;
      DAT_ffffdfca = 0xd1;
      DAT_ffffdfcb = 0;
      DAT_ffffdfc8 = 3;
      if (DAT_ffffdfb0 == '\x01') {
        DAT_ffffdfcc = 0x85;
      }
      else {
        DAT_ffffdfcc = 0x81;
      }
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}



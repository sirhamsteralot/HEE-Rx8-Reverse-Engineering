/* ROM address: 0x0000170a; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000170a (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000170a(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x28;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\x01') {
    DAT_ffffdfcb = 0x22;
  }
  else if ((*(short *)(param_1 + 2) == 3) && (*(char *)(param_1 + 4) == '\x01')) {
    if (*(char *)(param_1 + 6) == '\x01') {
      if ((*(char *)(param_1 + 5) == '\0') || (*(char *)(param_1 + 5) == '\x01')) {
        DAT_ffffdfc6 = 0x68;
        DAT_ffffdfc8 = 0;
      }
      else {
        DAT_ffffdfcb = 0x31;
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



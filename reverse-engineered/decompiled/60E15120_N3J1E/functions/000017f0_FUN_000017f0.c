/* ROM address: 0x000017f0; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000017f0 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000017f0(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x10;
  DAT_ffffdfc8 = 2;
  if (*(short *)(param_1 + 2) == 1) {
    if (*(char *)(param_1 + 4) == -0x7f) {
      ref_handleException_(0);
      DAT_ffffdfca = 0x81;
    }
    else {
      if (*(char *)(param_1 + 4) != -0x7b) {
        DAT_ffffdfcb = 0x12;
        goto LAB_0000184c;
      }
      DAT_ffffdfca = 0x85;
      DAT_ffffdfb0 = 1;
    }
    DAT_ffffdfc6 = 0x50;
    DAT_ffffdfc8 = 1;
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
LAB_0000184c:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}



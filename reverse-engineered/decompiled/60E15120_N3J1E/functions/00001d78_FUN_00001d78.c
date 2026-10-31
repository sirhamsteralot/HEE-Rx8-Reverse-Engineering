/* ROM address: 0x00001d78; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001d78 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001d78(int param_1)

{
  ushort uVar1;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0xb1;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else if (*(short *)(param_1 + 2) == 3) {
    if (((*(char *)(param_1 + 4) == '\0') && (*(char *)(param_1 + 5) == -0x4e)) &&
       (*(char *)(param_1 + 6) == '\0')) {
      uVar1 = FUN_00001008();
      if (uVar1 < 100) {
        DAT_ffffdfb4._0_1_ = 0;
        DAT_ffffdfb3 = 1;
        DAT_ffffdfc6 = 0xf1;
        DAT_ffffdfca = 0;
        DAT_ffffdfcb = 0xb2;
        DAT_ffffdfc8 = 2;
      }
      else {
        DAT_ffffdfcb = 0x10;
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



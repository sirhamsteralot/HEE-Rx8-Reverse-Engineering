/* ROM address: 0x00001c04; body bytes: 256; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00001c04 (256 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001c04(int param_1)

{
  ushort uVar1;
  char *local_24;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x36;
  DAT_ffffdfc8 = 2;
  if ((DAT_ffffdfb0 == '\0') || (DAT_ffffdfb4._0_1_ == '\0')) {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 0x400) {
    uVar1 = 0;
    local_24 = (char *)(param_1 + 4);
    do {
      *DAT_ffffdfc0 = *local_24;
      if (*DAT_ffffdfc0 == (&DAT_00001ff4)[DAT_ffffdfc5]) {
        DAT_ffffdfc5 = DAT_ffffdfc5 + 1;
        if (DAT_ffffdfc5 == 8) {
          DAT_ffffdfc4 = '\x01';
        }
      }
      else {
        DAT_ffffdfc5 = 1;
      }
      uVar1 = uVar1 + 1;
      DAT_ffffdfc0 = DAT_ffffdfc0 + 1;
      local_24 = local_24 + 1;
    } while (uVar1 < 0x400);
    DAT_ffffdfbc = DAT_ffffdfbc + -0x400;
    if (DAT_ffffdfbc < 1) {
      if (DAT_ffffdfc4 == '\0') {
        DAT_ffffdfcb = 0x72;
        DAT_ffffdfb4._0_1_ = '\0';
      }
      else {
        DAT_ffffdfcb = 0x78;
        FUN_000011fa(&DAT_ffffdfc6);
        FUN_00001090(_DAT_ffffdfb8);
      }
    }
    else if (DAT_ffffdfc4 == '\x01') {
      DAT_ffffdfb4._0_1_ = '\0';
      DAT_ffffdfcb = 0x72;
    }
    else {
      DAT_ffffdfc6 = 0x76;
      DAT_ffffdfc8 = 0;
    }
  }
  else {
    DAT_ffffdfb4._0_1_ = '\0';
    DAT_ffffdfcb = 0x72;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}



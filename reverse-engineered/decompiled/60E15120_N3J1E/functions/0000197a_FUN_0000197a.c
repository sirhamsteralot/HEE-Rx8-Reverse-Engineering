/* ROM address: 0x0000197a; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000197a (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000197a(int param_1)

{
  undefined4 uVar1;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x3e;
  DAT_ffffdfcb = 0x12;
  DAT_ffffdfc8 = 0xff;
  if (*(short *)(param_1 + 2) == 1) {
    if (*(char *)(param_1 + 4) == '\x01') {
      DAT_ffffdfc6 = 0x7e;
      DAT_ffffdfc8 = 0;
    }
    else if (*(char *)(param_1 + 4) != '\x02') {
      DAT_ffffdfc8 = 2;
    }
  }
  else {
    DAT_ffffdfc8 = 2;
  }
  if (DAT_ffffdfc8 == 0xff) {
    return 0xff;
  }
  uVar1 = FUN_000011fa(&DAT_ffffdfc6);
  return uVar1;
}



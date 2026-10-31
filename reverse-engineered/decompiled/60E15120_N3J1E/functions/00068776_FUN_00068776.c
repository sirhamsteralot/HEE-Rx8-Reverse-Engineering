/* ROM address: 0x00068776; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067066 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068776(char param_1)

{
  if (param_1 == '\0') {
    DAT_ffffddd0 = 0;
    FUN_000687c4();
  }
  else if (param_1 == '\x10') {
    DAT_ffffddd0 = 0x10;
    FUN_000687e8();
  }
  else if (param_1 == ' ') {
    DAT_ffffddd0 = 0x20;
    FUN_00068826();
  }
  else if (param_1 == '0') {
    DAT_ffffddd0 = 0x30;
    FUN_00068868();
  }
  ref_txCAN_EventBased(&DAT_0004e00c);
  return;
}



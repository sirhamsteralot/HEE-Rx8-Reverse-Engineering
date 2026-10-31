/* ROM address: 0x00068826; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067116 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068826(void)

{
  DAT_ffffddd0 = DAT_ffffddd0 | DAT_ffffdde3;
  FUN_00067e78((int)DAT_ffffdde2,&DAT_ffffddd1,7);
  if (DAT_ffffdde3 < 0xf) {
    DAT_ffffdde3 = DAT_ffffdde3 + 1;
  }
  else {
    DAT_ffffdde3 = '\0';
  }
  DAT_ffffdde1 = 10;
  FUN_00068bc6(4,0x30);
  return;
}



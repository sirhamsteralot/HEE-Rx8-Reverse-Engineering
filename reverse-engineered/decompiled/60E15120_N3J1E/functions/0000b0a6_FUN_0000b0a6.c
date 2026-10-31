/* ROM address: 0x0000b0a6; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b0a6 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b0a6(void)

{
  DAT_ffffa206 = DAT_ffffa206 + 1;
  if (1 < DAT_ffffa206) {
    DAT_ffffa206 = 0;
  }
  if (DAT_ffffa206 == 0) {
    DAT_ffffa1fa = ADDR23H_B;
    DAT_ffffa1fe = ADDR11H_B;
    if (1000.0 < DAT_ffffa1d8) {
      if (1050.0 < DAT_ffffa1d8) {
        DAT_ffffa204 = '\0';
      }
    }
    else {
      DAT_ffffa204 = '\x01';
    }
    FUN_00006f16(0);
    FUN_0000b114((int)DAT_ffffa204);
    DAT_ffffa205 = 0;
  }
  return;
}



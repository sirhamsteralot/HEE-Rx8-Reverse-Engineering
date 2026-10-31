/* ROM address: 0x00028df2; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002979a (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can216RXTimer(void)

{
  if (can216_unpacked_field_0_ffffbad4 == -1) {
    if (DAT_ffffbad2 != 0) {
      DAT_ffffbad2 = DAT_ffffbad2 + -1;
    }
  }
  else {
    DAT_ffffbad2 = 0x3e;
  }
  return;
}



/* ROM address: 0x00029032; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000299da (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_CANRX216TimeoutCount(void)

{
  if (DAT_ffffa400 == '\0') {
    if (DAT_ffffbac0 != '\0') {
      DAT_ffffbac0 = DAT_ffffbac0 + -1;
    }
  }
  else {
    DAT_ffffbac0 = '\x10';
  }
  return;
}



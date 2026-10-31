/* ROM address: 0x0004e566; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004c03a (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004e566(void)

{
  if (DAT_ffffd266 == '\0') {
    DAT_ffffcf87 = 0;
  }
  else if (DAT_ffffcf86 == '\x01') {
    DAT_ffffcf87 = 1;
  }
  if (DAT_ffffcf85 != '\0') {
    DAT_ffffcf85 = DAT_ffffcf85 + -1;
  }
  if ((DAT_ffffcf88 == '\0') || (DAT_ffffcf85 != '\0')) {
    DAT_ffffcf86 = 0;
  }
  else {
    DAT_ffffcf86 = 1;
  }
  DAT_ffffcf88 = DAT_ffffcf85;
  return;
}



/* ROM address: 0x0004f640; body bytes: 204; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d200 (204 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004f640(void)

{
  if ((((((DAT_ffffcfc6 == '\x01') || (DAT_ffffcfc0 == '\x01')) && (DAT_ffffcffa == '\0')) &&
       (DAT_ffffcfa6 <= DAT_ffffcfaa)) ||
      (((DAT_ffffcfbf == '\x01' || (DAT_ffffcfc0 == '\x01')) &&
       ((DAT_ffffcffb == '\0' && (DAT_ffffcfa8 <= DAT_ffffcfaa)))))) ||
     ((DAT_ffffd001 == '\0' && (DAT_ffffd0f2 == '\x01')))) {
    DAT_ffffcff8 = DAT_ffffcfb0;
  }
  else if ((DAT_ffffcff9 == '\n') && (DAT_ffffcff8 != '\0')) {
    DAT_ffffcff8 = DAT_ffffcff8 + -1;
  }
  DAT_ffffd001 = DAT_ffffd0f2;
  if ((DAT_ffffcfbe == '\x01') && (DAT_ffffcfa6 <= DAT_ffffcfaa)) {
    DAT_ffffcffa = 1;
  }
  else {
    DAT_ffffcffa = 0;
  }
  return DAT_ffffcfbe;
}



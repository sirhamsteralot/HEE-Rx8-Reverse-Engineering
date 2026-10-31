/* ROM address: 0x00029e76; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a5ca (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00029e76(void)

{
  DAT_ffffbb5b = 0;
  if (DAT_ffffbb48 == '\x01') {
    DAT_ffffbb5b = 0x80;
  }
  if (DAT_ffffbb49 == '\x01') {
    DAT_ffffbb5b = DAT_ffffbb5b | 4;
  }
  if (DAT_ffffbb4a == '\x01') {
    DAT_ffffbb5b = DAT_ffffbb5b | 1;
  }
  return DAT_ffffbb4a;
}



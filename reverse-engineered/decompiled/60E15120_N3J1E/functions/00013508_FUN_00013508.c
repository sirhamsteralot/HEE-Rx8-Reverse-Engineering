/* ROM address: 0x00013508; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013368 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00013508(void)

{
  if ((DAT_ffffa415 == '\0') && (DAT_ffffa716 != '\0')) {
    DAT_ffffa714 = 1;
  }
  if ((DAT_ffffa415 == '\f') && (DAT_ffffa716 != '\f')) {
    DAT_ffffa714 = 0;
  }
  if ((DAT_ffffa414 == '\0') && (DAT_ffffa717 != '\0')) {
    DAT_ffffa715 = 1;
  }
  if ((DAT_ffffa414 == '\x03') && (DAT_ffffa717 != '\x03')) {
    DAT_ffffa715 = 0;
  }
  DAT_ffffa716 = DAT_ffffa415;
  DAT_ffffa717 = DAT_ffffa414;
  return;
}



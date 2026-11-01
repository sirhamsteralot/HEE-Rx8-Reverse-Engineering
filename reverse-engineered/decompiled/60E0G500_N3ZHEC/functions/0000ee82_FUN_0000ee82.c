/* ROM address: 0x0000ee82; body bytes: 120; decompiled */

void rev_limit_conditionals(void)

{
  if (18.0 <= DAT_ffffaa10) {
    if (20.0 <= DAT_ffffaa10) {
      DAT_ffffa4a6 = 0;
    }
  }
  else {
    DAT_ffffa4a6 = 1;
  }
  if ((((DAT_ffffb5a4 == '\0') && (DAT_ffffbb54 != '\0')) && (DAT_ffffa4ad == '\0')) &&
     (DAT_ffffbb54 != '\a')) {
    DAT_ffffa4ae = '\f';
  }
  DAT_ffffa4aa = DAT_ffffa4ae != '\0';
  if (DAT_ffffa4aa) {
    DAT_ffffa4ae = DAT_ffffa4ae + -1;
  }
  DAT_ffffa4ad = DAT_ffffbb54;
  return;
}



/* ROM address: 0x0001bd8a; body bytes: 70; decompiled */

void FUN_0001bd8a(void)

{
  DAT_ffffadd4 = DAT_ffff9f08;
  DAT_ffffadfc = DAT_ffffa222;
  DAT_ffffada8 = DAT_ffffa218;
  if (DAT_ffffae4a == '\0') {
    DAT_ffffadcc = DAT_ffffa218;
    DAT_ffffae4a = '\x01';
  }
  else {
    DAT_ffffadcc = rx8_first_order_filter(DAT_ffffa218,DAT_ffffadcc,0.25,1e-05);
  }
  return;
}



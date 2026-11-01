/* ROM address: 0x000349d8; body bytes: 110; decompiled */

char FUN_000349d8(void)

{
  char cVar1;
  
  if (DAT_ffffadbc <= 33.6) {
    DAT_ffffc11e = 0;
  }
  else {
    DAT_ffffc11e = FUN_00002460((int)DAT_ffffc11e,1);
  }
  if (DAT_ffffb5aa == '\0') {
    DAT_ffffc120 = FUN_00002460((int)DAT_ffffc120,1);
  }
  else {
    DAT_ffffc120 = 0;
  }
  cVar1 = DAT_ffffc127;
  if (DAT_ffffc127 == '\x01') {
    DAT_ffffc122 = 0xfa;
    DAT_ffffc127 = '\0';
  }
  else if (DAT_ffffc122 != 0) {
    DAT_ffffc122 = DAT_ffffc122 + -1;
  }
  return cVar1;
}



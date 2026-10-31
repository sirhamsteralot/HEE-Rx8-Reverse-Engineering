/* ROM address: 0x00024ff0; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025878 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00024ff0(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffb56b;
  DAT_ffffb56c = DAT_ffffb56b;
  if (DAT_ffffb569 == '\x01') {
    DAT_ffffb569 = '\0';
    DAT_ffffb56a = '@';
    DAT_ffffb56b = '\x01';
  }
  else if ((DAT_ffffb56a != '\0') && (DAT_ffffb56a = DAT_ffffb56a + -1, DAT_ffffb56a == '\0')) {
    DAT_ffffb56b = '\0';
  }
  if ((DAT_ffffb56b == '\0') && (cVar1 == '\x01')) {
    DAT_ffffb568 = '\f';
  }
  else if ((DAT_ffffb56b == '\x01') && (DAT_ffffb568 != '\0')) {
    DAT_ffffb568 = DAT_ffffb568 + -1;
  }
  FUN_000074e0(DAT_ffffb568 != '\0');
  return;
}



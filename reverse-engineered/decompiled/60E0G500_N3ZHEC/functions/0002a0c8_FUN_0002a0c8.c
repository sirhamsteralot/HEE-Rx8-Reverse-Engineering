/* ROM address: 0x0002a0c8; body bytes: 130; decompiled */

char FUN_0002a0c8(void)

{
  char cVar1;
  
  DAT_ffffbb7f = 0;
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbb7f = 0x80;
  }
  if (DAT_ffffbb8d == '\x01') {
    DAT_ffffbb7f = DAT_ffffbb7f | 0x40;
  }
  if (DAT_ffffbb8e == '\x01') {
    DAT_ffffbb7f = DAT_ffffbb7f | 0x20;
  }
  if (DAT_ffffbb8f == '\x01') {
    DAT_ffffbb7f = DAT_ffffbb7f | 0x10;
  }
  if (DAT_ffffbb90 == '\x01') {
    DAT_ffffbb7f = DAT_ffffbb7f | 8;
  }
  cVar1 = DAT_ffffbb90;
  if (0x7c < DAT_ffffbc2f) {
    cVar1 = '\x04';
    DAT_ffffbb7f = DAT_ffffbb7f | 4;
  }
  if (DAT_ffffcda0 == '\0') {
    cVar1 = '\x02';
    DAT_ffffbb7f = DAT_ffffbb7f | 2;
  }
  if (DAT_ffffad90 == '\0') {
    cVar1 = '\x01';
    DAT_ffffbb7f = DAT_ffffbb7f | 1;
  }
  return cVar1;
}



/* ROM address: 0x00029538; body bytes: 130; decompiled */

char FUN_00029538(void)

{
  char cVar1;
  
  DAT_ffffbb17 = 0;
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb17 = 0x80;
  }
  if (DAT_ffffbb25 == '\x01') {
    DAT_ffffbb17 = DAT_ffffbb17 | 0x40;
  }
  if (DAT_ffffbb26 == '\x01') {
    DAT_ffffbb17 = DAT_ffffbb17 | 0x20;
  }
  if (DAT_ffffbb27 == '\x01') {
    DAT_ffffbb17 = DAT_ffffbb17 | 0x10;
  }
  if (DAT_ffffbb28 == '\x01') {
    DAT_ffffbb17 = DAT_ffffbb17 | 8;
  }
  cVar1 = DAT_ffffbb28;
  if (0x7c < DAT_ffffbbc7) {
    cVar1 = '\x04';
    DAT_ffffbb17 = DAT_ffffbb17 | 4;
  }
  if (safe_mode_ffffcd60 == '\0') {
    cVar1 = '\x02';
    DAT_ffffbb17 = DAT_ffffbb17 | 2;
  }
  if (DAT_ffffad18 == '\0') {
    cVar1 = '\x01';
    DAT_ffffbb17 = DAT_ffffbb17 | 1;
  }
  return cVar1;
}



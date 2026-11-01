/* ROM address: 0x0002c984; body bytes: 64; decompiled */

char FUN_0002c984(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((((DAT_ffffcdfe == '\x01') || (cVar1 = '\x01', DAT_ffffcdff == '\x01')) ||
      (cVar1 = '\x01', DAT_ffffce00 == '\x01')) || (cVar1 = DAT_ffffce01, DAT_ffffce01 == '\x01')) {
    DAT_ffffbc95 = 1;
  }
  else {
    DAT_ffffbc95 = 0;
  }
  return cVar1;
}



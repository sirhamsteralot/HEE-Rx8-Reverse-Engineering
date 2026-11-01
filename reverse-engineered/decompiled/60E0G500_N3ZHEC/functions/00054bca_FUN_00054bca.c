/* ROM address: 0x00054bca; body bytes: 96; decompiled */

char FUN_00054bca(void)

{
  char cVar1;
  
  if ((((DAT_ffffd1f1 == '\x01') || (DAT_ffffcd4f == '\x01')) || (DAT_ffffcd50 == '\x01')) ||
     ((DAT_ffffcd51 == '\x01' || (DAT_ffffcd52 == '\x01')))) {
    cVar1 = FUN_000671a4(0x43);
    if (cVar1 == '\0') {
      DAT_ffffd1f0 = 1;
    }
  }
  else {
    cVar1 = '\0';
    DAT_ffffd1f0 = 0;
  }
  return cVar1;
}



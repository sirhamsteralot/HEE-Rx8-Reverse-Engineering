/* ROM address: 0x0003b110; body bytes: 140; decompiled */

char FUN_0003b110(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc581 = 0;
    DAT_ffffc582 = 0;
    cVar1 = '\x01';
  }
  else {
    if (((DAT_ffffc588 == '\x01') && (DAT_ffffc589 == '\x01')) &&
       (cVar1 = ref_getFaultStatus__(0x2f), cVar1 == '\0')) {
      DAT_ffffc582 = 1;
      DAT_ffffc581 = 0;
    }
    if (((DAT_ffffc585 == '\x01') || (DAT_ffffc586 == '\x01')) ||
       (cVar1 = DAT_ffffc584, DAT_ffffc584 == '\x01')) {
      cVar1 = ref_getFaultStatus__(0x2f);
      if (cVar1 == '\0') {
        DAT_ffffc581 = 1;
        DAT_ffffc582 = 0;
      }
    }
  }
  return cVar1;
}



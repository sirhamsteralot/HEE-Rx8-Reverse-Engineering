/* ROM address: 0x00054426; body bytes: 96; decompiled */

char FUN_00054426(void)

{
  char cVar1;
  
  if ((((DAT_ffffd1b5 == '\x01') || (DAT_ffffcd0f == '\x01')) || (DAT_ffffcd10 == '\x01')) ||
     ((DAT_ffffcd11 == '\x01' || (DAT_ffffcd12 == '\x01')))) {
    cVar1 = ref_getFaultStatus__(0x43);
    if (cVar1 == '\0') {
      DAT_ffffd1b4 = 1;
    }
  }
  else {
    cVar1 = '\0';
    DAT_ffffd1b4 = 0;
  }
  return cVar1;
}



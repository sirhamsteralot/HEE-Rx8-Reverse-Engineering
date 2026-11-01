/* ROM address: 0x0002ecdc; body bytes: 118; decompiled */

char FUN_0002ecdc(void)

{
  char cVar1;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff868c,0);
  if (DAT_ffffaae0 == '\x01') {
    if (DAT_ffffbdbf == '\0') {
      DAT_ffffbdba = 0;
    }
    else if (DAT_ffffbdba != 0) {
      DAT_ffffbdba = DAT_ffffbdba + -1;
    }
  }
  else {
    DAT_ffffbdba = 0;
  }
  if ((cVar1 == '\x01') || (DAT_ffffbdba != 0)) {
    cVar1 = '\x01';
    DAT_ffffbdb8 = 1;
  }
  else if (cVar1 == '\0') {
    DAT_ffffbdb8 = 0;
  }
  DAT_ffffbdbf = DAT_ffffaae0;
  return cVar1;
}



/* ROM address: 0x0002fc40; body bytes: 122; decompiled */

void FUN_0002fc40(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffbdff;
  if (DAT_ffffaa10 < 110.0) {
    if (DAT_ffffaa10 < 107.5) {
      DAT_ffffbdff = '\0';
    }
  }
  else {
    DAT_ffffbdff = '\x01';
  }
  if (DAT_ffffbdf6 == 0) {
    if ((DAT_ffffbdff == '\x01') && (DAT_ffffbdf6 = 0x138, cVar1 != '\0')) {
      if (DAT_ffffbde2 == '\x01') {
        DAT_ffffbde2 = '\0';
      }
      else {
        DAT_ffffbde2 = '\x01';
      }
    }
    else {
      DAT_ffffbde2 = '\x01';
    }
  }
  if (DAT_ffffbdf6 != 0) {
    DAT_ffffbdf6 = DAT_ffffbdf6 + -1;
  }
  return;
}



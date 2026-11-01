/* ROM address: 0x00033800; body bytes: 82; decompiled */

int FUN_00033800(void)

{
  int iVar1;
  char cVar2;
  
  if ((DAT_ffffcd4e & 0x40) == 0) {
    if ((DAT_ffffcd4e & 0x20) == 0) {
      iVar1 = -((((int)(char)DAT_ffffcd4e & 0x80U) == 0) - 1);
      if (iVar1 == 1) {
        cVar2 = '\x02';
      }
      else {
        cVar2 = '\x03';
      }
    }
    else {
      cVar2 = '\x01';
      iVar1 = 1;
    }
  }
  else {
    cVar2 = '\0';
    iVar1 = 1;
  }
  DAT_ffffc05c = cVar2 << 4;
  return iVar1;
}



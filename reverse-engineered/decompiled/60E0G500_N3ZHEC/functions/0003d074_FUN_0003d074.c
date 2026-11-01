/* ROM address: 0x0003d074; body bytes: 260; decompiled */

char FUN_0003d074(void)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  
  bVar3 = false;
  cVar2 = '\x01';
  if (DAT_ffffc5fe == '\0') {
    if (DAT_ffffaa84 <= 2.0) {
      if (DAT_ffffc638 == '\0') {
        bVar3 = true;
      }
      else {
        DAT_ffffc638 = DAT_ffffc638 + -1;
      }
    }
    else {
      DAT_ffffc638 = '\x03';
    }
  }
  else {
    DAT_ffffc638 = '\0';
    bVar3 = true;
  }
  if (((DAT_ffffa41c == '\0') || (DAT_ffffc600 == '\x01')) || (DAT_ffffc604 == '\x01')) {
    DAT_ffffc639 = -0x7d;
  }
  else if (DAT_ffffc639 == '\0') {
    cVar2 = '\0';
  }
  else {
    DAT_ffffc639 = DAT_ffffc639 + -1;
  }
  cVar1 = DAT_ffffd201;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc63b = 0;
    DAT_ffffc63c = 0;
  }
  else if (((DAT_ffffa41c != '\0') && (cVar1 = '\x01', !bVar3)) && (cVar1 = '\x01', cVar2 != '\x01')
          ) {
    if (DAT_ffffc63a != '\0') {
      DAT_ffffc63a = DAT_ffffc63a + -1;
      return cVar2;
    }
    if (DAT_ffffc63d != '\x01') {
      return DAT_ffffc63d;
    }
    cVar2 = FUN_000671a4(0x25);
    if (cVar2 != '\0') {
      return cVar2;
    }
    DAT_ffffc63b = 0;
    DAT_ffffc63c = 1;
    return '\0';
  }
  DAT_ffffc63a = 0x83;
  return cVar1;
}



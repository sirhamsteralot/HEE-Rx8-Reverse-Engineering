/* ROM address: 0x000467d0; body bytes: 144; decompiled */

void FUN_000467d0(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffb55c;
  cVar1 = DAT_ffffad90;
  if (DAT_ffffcc4c != '\0') {
    if (DAT_ffffcc4c != '\x01') {
      DAT_ffffcc52 = cVar1;
      DAT_ffffcc53 = cVar2;
      return;
    }
    if ((DAT_ffffad90 == DAT_ffffcc52) && (DAT_ffffb55c == DAT_ffffcc53)) {
      if (DAT_ffffad90 != DAT_ffffb55c) {
        DAT_ffffcc50 = 0;
        DAT_ffffcc4e = FUN_00002460((int)DAT_ffffcc4e,1);
        DAT_ffffcc52 = cVar1;
        DAT_ffffcc53 = cVar2;
        return;
      }
      DAT_ffffcc4e = 0;
      DAT_ffffcc50 = FUN_00002460((int)DAT_ffffcc50,1);
      DAT_ffffcc52 = cVar1;
      DAT_ffffcc53 = cVar2;
      return;
    }
  }
  DAT_ffffcc50 = 0;
  DAT_ffffcc4e = 0;
  DAT_ffffcc52 = cVar1;
  DAT_ffffcc53 = cVar2;
  return;
}



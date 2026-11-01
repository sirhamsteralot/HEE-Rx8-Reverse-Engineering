/* ROM address: 0x00045c7a; body bytes: 54; decompiled */

char FUN_00045c7a(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  
  uVar2 = DAT_fffff74e;
  bVar1 = (uVar2 & 0x8000) == 0;
  if (bVar1) {
    cVar3 = DAT_ffffcc11;
    if (DAT_ffffcc11 == '\x01') {
      DAT_ffffcc10 = 1;
    }
  }
  else {
    cVar3 = bVar1;
    if (DAT_ffffcc11 == '\0') {
      DAT_ffffcc10 = 0;
    }
  }
  DAT_ffffcc11 = bVar1;
  return cVar3;
}



/* ROM address: 0x0004677e; body bytes: 82; decompiled */

undefined1 FUN_0004677e(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_000671a4(0x85);
  if ((((cVar1 == '\0') && (cVar1 = FUN_0003eaa4(&DAT_ffff8760,0), cVar1 == '\0')) &&
      (cVar1 = FUN_0003eaa4(&DAT_ffff8766,0), cVar1 == '\0')) && (DAT_ffffbdb4 == '\x01')) {
    DAT_ffffcc4c = 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    DAT_ffffcc4c = 0;
  }
  return uVar2;
}



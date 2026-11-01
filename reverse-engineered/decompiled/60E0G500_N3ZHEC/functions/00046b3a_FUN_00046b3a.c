/* ROM address: 0x00046b3a; body bytes: 84; decompiled */

undefined4 FUN_00046b3a(void)

{
  char cVar1;
  
  cVar1 = FUN_000671a4(0x46);
  if ((((cVar1 == '\0') && (DAT_ffffcd03 == '\x01')) &&
      (cVar1 = FUN_0003eaa4(&DAT_ffff8768,0), cVar1 == '\0')) &&
     ((DAT_ffffccfc == '\0' && (DAT_ffffccfd == '\0')))) {
    DAT_ffffcc68 = 1;
  }
  else {
    DAT_ffffcc68 = 0;
  }
  return 0;
}



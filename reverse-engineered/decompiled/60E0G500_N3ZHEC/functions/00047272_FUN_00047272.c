/* ROM address: 0x00047272; body bytes: 64; decompiled */

undefined4 FUN_00047272(void)

{
  char cVar1;
  
  cVar1 = FUN_000671a4(99);
  if (((cVar1 == '\0') && (DAT_ffffcd05 == '\x01')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff876c,0), cVar1 == '\0')) {
    DAT_ffffcc9c = 1;
    return 0;
  }
  DAT_ffffcc9c = 0;
  return 0;
}



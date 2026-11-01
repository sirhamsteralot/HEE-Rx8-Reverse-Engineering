/* ROM address: 0x000460c2; body bytes: 64; decompiled */

undefined4 FUN_000460c2(void)

{
  char cVar1;
  
  cVar1 = FUN_000671a4(0x6c);
  if (((cVar1 == '\0') && (DAT_ffffcd02 == '\x01')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8754,0), cVar1 == '\0')) {
    DAT_ffffcc30 = 1;
    return 0;
  }
  DAT_ffffcc30 = 0;
  return 0;
}



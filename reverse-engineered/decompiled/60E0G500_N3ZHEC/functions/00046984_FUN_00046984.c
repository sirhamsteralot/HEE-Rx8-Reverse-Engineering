/* ROM address: 0x00046984; body bytes: 64; decompiled */

undefined4 FUN_00046984(void)

{
  char cVar1;
  
  cVar1 = FUN_000671a4(0x62);
  if (((cVar1 == '\0') && (DAT_ffffcd04 == '\x01')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8764,0), cVar1 == '\0')) {
    DAT_ffffcc55 = 1;
    return 0;
  }
  DAT_ffffcc55 = 0;
  return 0;
}



/* ROM address: 0x00045d14; body bytes: 80; decompiled */

undefined4 FUN_00045d14(void)

{
  char cVar1;
  
  cVar1 = FUN_000671a4(0x4e);
  if ((((cVar1 == '\0') && (DAT_ffffcd04 == '\x01')) &&
      (cVar1 = FUN_0003eaa4(&DAT_ffff8750,0), cVar1 == '\0')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8766,0), cVar1 == '\0')) {
    DAT_ffffcc22 = 1;
    return 0;
  }
  DAT_ffffcc22 = 0;
  return 0;
}



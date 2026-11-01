/* ROM address: 0x00047756; body bytes: 64; decompiled */

undefined4 FUN_00047756(void)

{
  char cVar1;
  
  if (((DAT_ffffcd04 == '\x01') && (cVar1 = FUN_000671a4(0x5e), cVar1 == '\0')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8780,0), cVar1 == '\0')) {
    DAT_ffffccac = 1;
    return 0;
  }
  DAT_ffffccac = 0;
  return 0;
}



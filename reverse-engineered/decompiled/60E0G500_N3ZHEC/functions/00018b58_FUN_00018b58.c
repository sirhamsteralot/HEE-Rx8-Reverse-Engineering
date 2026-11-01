/* ROM address: 0x00018b58; body bytes: 82; decompiled */

undefined4 FUN_00018b58(void)

{
  char cVar1;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff8080,0);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_0003eaa4(&DAT_ffff8082,0), cVar1 != '\x01')) &&
      (cVar1 = FUN_0003eaa4(&DAT_ffff8084,0), cVar1 != '\x01')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8086,0), cVar1 != '\x01')) {
    DAT_ffffa998 = 0;
    return 0;
  }
  DAT_ffffa998 = 1;
  return 1;
}



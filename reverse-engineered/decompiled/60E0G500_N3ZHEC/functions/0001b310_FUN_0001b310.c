/* ROM address: 0x0001b310; body bytes: 114; decompiled */

undefined4 FUN_0001b310(void)

{
  char cVar1;
  
  DAT_ffffad80 = FUN_0005da90(0);
  DAT_ffffad81 = FUN_0005db2c(0);
  DAT_ffffad7c = FUN_0005dbf4(0);
  DAT_ffffad7e = FUN_0005dccc(0);
  cVar1 = FUN_0005c7a2(0x15);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_0005c7a2(0x16), cVar1 != '\x01')) &&
      (cVar1 = FUN_0005c7a2(0x17), cVar1 != '\x01')) &&
     (cVar1 = FUN_0005c7a2(0x18), cVar1 != '\x01')) {
    DAT_ffffad82 = 0;
    return 0;
  }
  DAT_ffffad82 = 1;
  return 1;
}



/* ROM address: 0x00053f18; body bytes: 82; decompiled */

undefined4 FUN_00053f18(void)

{
  char cVar1;
  
  cVar1 = FUN_0005f9f0(3,0);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_0005f9f0(4,0), cVar1 != '\x01')) &&
      (cVar1 = FUN_0005f9f0(5,0), cVar1 != '\x01')) && (cVar1 = FUN_0005f9f0(6,0), cVar1 != '\x01'))
  {
    DAT_ffffd1a8 = 0;
    return 0;
  }
  DAT_ffffd1a8 = 1;
  return 1;
}



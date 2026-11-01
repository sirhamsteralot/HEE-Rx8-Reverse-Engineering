/* ROM address: 0x0000dfb2; body bytes: 100; decompiled */

uint FUN_0000dfb2(void)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = (uint)DAT_ffffaae0;
  if ((uVar1 == 1) && (uVar1 = 1, DAT_ffffb5e8 != '\x01')) {
    if ((DAT_ffffc528 == '\0') &&
       (((DAT_ffffa408 == '\0' && (cVar2 = FUN_000671a4(0x82), cVar2 == '\0')) &&
        (uVar1 = (uint)DAT_ffffcd4c, (uVar1 & 0x80) == 0)))) {
      DAT_ffffa404 = 1;
    }
    else {
      uVar1 = 0;
      DAT_ffffa404 = 0;
    }
  }
  return uVar1;
}



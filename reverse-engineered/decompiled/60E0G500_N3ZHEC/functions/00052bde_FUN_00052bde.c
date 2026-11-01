/* ROM address: 0x00052bde; body bytes: 60; decompiled */

char FUN_00052bde(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffcfc2;
  if ((DAT_ffffcfc2 == '\x01') && (DAT_ffffd020 - DAT_ffffd024 < 0.002)) {
    cVar1 = FUN_000671a4(0x30);
    if (cVar1 == '\0') {
      DAT_ffffd151 = 1;
    }
  }
  return cVar1;
}



/* ROM address: 0x000529fa; body bytes: 64; decompiled */

char FUN_000529fa(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff86ac);
  cVar1 = DAT_ffffcfc2;
  if ((DAT_ffffcfc2 == '\x01') && (DAT_ffffd020 < DAT_ffffd024 + fVar2)) {
    cVar1 = FUN_000671a4(0x77);
    if (cVar1 == '\0') {
      DAT_ffffd153 = 1;
    }
  }
  return cVar1;
}



/* ROM address: 0x00052e7c; body bytes: 86; decompiled */

char FUN_00052e7c(void)

{
  char cVar1;
  float fVar2;
  
  cVar1 = DAT_ffffcfc2;
  if (DAT_ffffcfc2 == '\x01') {
    fVar2 = DAT_ffffd020;
    if (DAT_ffffd020 < 0.015) {
      cVar1 = FUN_000671a4(0x75);
      if (cVar1 == '\0') {
        DAT_ffffd14b = 1;
      }
    }
    if (0.0366 < fVar2) {
      cVar1 = FUN_000671a4(0x76);
      if (cVar1 == '\0') {
        DAT_ffffd14c = 1;
      }
    }
  }
  return cVar1;
}



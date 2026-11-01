/* ROM address: 0x00052126; body bytes: 72; decompiled */

char FUN_00052126(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff86ac);
  cVar1 = DAT_ffffcfc2;
  if ((DAT_ffffcfc2 == '\x01') && ((DAT_ffffd024 + fVar2) - DAT_ffffd11c < 0.0003)) {
    cVar1 = FUN_000671a4(0x2d);
    if (cVar1 == '\0') {
      DAT_ffffd130 = 1;
    }
  }
  return cVar1;
}



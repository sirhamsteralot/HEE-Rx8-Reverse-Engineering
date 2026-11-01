/* ROM address: 0x000166c2; body bytes: 120; decompiled */

char FUN_000166c2(void)

{
  char cVar1;
  char cVar2;
  float fVar3;
  
  fVar3 = DAT_ffffa8b4;
  cVar1 = FUN_00002440(DAT_ffffa8b4,0,0x3727c5ac);
  cVar2 = DAT_ffffa8cc;
  if ((((DAT_ffffa8cc != '\x01') || (DAT_ffffa7bc <= DAT_ffffb5b8)) ||
      ((DAT_ffffa8cd != '\x01' && (cVar2 = DAT_ffffa8ce, DAT_ffffa8ce != '\x01')))) ||
     (((cVar2 = DAT_ffffa428, DAT_ffffa428 != '\x01' || (0.01 <= fVar3)) || (cVar1 == '\0')))) {
    DAT_ffffa8b8 = 0;
  }
  else {
    DAT_ffffa8b8 = 1;
  }
  return cVar2;
}



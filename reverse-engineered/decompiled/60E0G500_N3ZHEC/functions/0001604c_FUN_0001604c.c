/* ROM address: 0x0001604c; body bytes: 302; decompiled */

uint FUN_0001604c(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  
  cVar2 = DAT_ffffa7c5;
  bVar1 = DAT_ffffa7c4;
  fVar5 = rx8_absolute_difference(DAT_ffffa7bc,DAT_ffffb5c0);
  fVar6 = DAT_ffffa848;
  cVar3 = FUN_00002440(DAT_ffffa8dc,0,0x3727c5ac);
  uVar4 = (uint)bVar1;
  if (((((uVar4 != 1) || (DAT_ffffa8a2 < 0x138)) || (cVar2 != '\0')) ||
      ((((DAT_ffffa8a4 < 0x138 || (DAT_ffffaa10 < 80.0)) ||
        ((60.0 <= DAT_ffffae54 || ((37.0 < fVar5 || (cVar3 != '\0')))))) || (0.035 < DAT_ffffa7b4)))
      ) || ((((35.0 < DAT_ffffb360 || (fVar6 <= DAT_ffffa850)) || (DAT_ffffa84c <= fVar6)) ||
            ((DAT_ffffa7c7 != '\0' || (DAT_ffffccd1 != '\0')))))) {
    DAT_ffffa8a0 = 0;
  }
  else {
    DAT_ffffa8a0 = 1;
  }
  if (uVar4 == 1) {
    uVar4 = FUN_00002460((int)(short)DAT_ffffa8a2,1);
    DAT_ffffa8a2 = (ushort)uVar4;
  }
  else {
    DAT_ffffa8a2 = 0;
  }
  if (cVar2 == '\0') {
    uVar4 = FUN_00002460((int)(short)DAT_ffffa8a4,1);
    DAT_ffffa8a4 = (ushort)uVar4;
  }
  else {
    DAT_ffffa8a4 = 0;
  }
  return uVar4;
}



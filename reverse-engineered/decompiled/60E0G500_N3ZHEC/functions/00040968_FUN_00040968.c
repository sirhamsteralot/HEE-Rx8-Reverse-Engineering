/* ROM address: 0x00040968; body bytes: 294; decompiled */

undefined2 * FUN_00040968(void)

{
  char cVar2;
  char cVar3;
  undefined2 *puVar1;
  float fVar4;
  float fVar5;
  float fVar6;
  
  DAT_ffffc84c = FUN_00002120(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006b9f8);
  fVar6 = 0.0;
  cVar2 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  fVar4 = rx8_absolute_difference(DAT_ffffcb28,fVar6);
  fVar5 = rx8_absolute_difference(DAT_ffffcb2c,fVar6);
  fVar6 = rx8_absolute_difference(DAT_ffffadc8,fVar6);
  cVar3 = FUN_000671a4(0x1c);
  if (((((((cVar3 != '\0') || (DAT_ffffaaf9 != '\x01')) || (DAT_ffffae97 != '\x01')) ||
        ((DAT_ffffc98c != '\x01' || (DAT_ffffc84c == '\0')))) ||
       ((50.0 <= fVar4 || ((0.05 <= fVar5 || (0.42 <= fVar6)))))) || (0x31 < DAT_ffffc828)) ||
     ((DAT_ffffd201 != '\0' ||
      ((puVar1 = (undefined2 *)0x0, cVar2 != '\0' &&
       ((0.15 <= DAT_ffffb290 || (puVar1 = &DAT_ffffb364, DAT_ffffb364 < 0x271)))))))) {
    puVar1 = &DAT_0007aa38;
    DAT_ffffc770 = 0;
    DAT_ffffc820 = 0x20;
  }
  else {
    DAT_ffffc770 = 1;
    if (DAT_ffffc820 != 0) {
      DAT_ffffc820 = DAT_ffffc820 + -1;
    }
  }
  return puVar1;
}



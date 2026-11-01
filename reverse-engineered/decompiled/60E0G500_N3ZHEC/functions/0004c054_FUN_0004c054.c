/* ROM address: 0x0004c054; body bytes: 152; decompiled */

undefined4 * FUN_0004c054(void)

{
  char cVar1;
  undefined4 *puVar2;
  float fVar3;
  float arg1;
  undefined4 uVar4;
  
  uVar4 = 0;
  fVar3 = (float)FUN_000024c0(0x41000000,0,(int)DAT_ffffa424);
  arg1 = (float)FUN_000024c0(0x44800000,uVar4,(int)DAT_ffffa426);
  cVar1 = DAT_ffffce85;
  if ((DAT_ffffce89 == '\0') && (DAT_ffffce85 == '\x01')) {
    DAT_ffffce78 = 0;
    puVar2 = (undefined4 *)0x1;
  }
  else {
    puVar2 = (undefined4 *)(uint)DAT_ffffa428;
    if (puVar2 == (undefined4 *)0x1) {
      fVar3 = rx8_max_float(fVar3,arg1);
      fVar3 = rx8_min_float(fVar3,3.6e+07);
      fVar3 = fVar3 / 32.0;
      puVar2 = &DAT_0004c1e0;
      if (2.1474836e+09 < fVar3) {
        puVar2 = &DAT_0004c1e4;
        fVar3 = fVar3 + -4.2949673e+09;
      }
      DAT_ffffce78 = (int)fVar3;
    }
  }
  DAT_ffffce89 = cVar1;
  return puVar2;
}



/* ROM address: 0x0004b8a8; body bytes: 152; decompiled */

undefined4 * FUN_0004b8a8(void)

{
  char cVar1;
  undefined4 *puVar2;
  float fVar3;
  float arg1;
  undefined4 uVar4;
  
  uVar4 = 0;
  fVar3 = (float)rx8_decode_u16_affine(0x41000000,0,(int)engine_running_timer_ffffa424);
  arg1 = (float)rx8_decode_u16_affine(0x44800000,uVar4,(int)engine_on_time_counter_ffffa426);
  cVar1 = DAT_ffffce49;
  if ((DAT_ffffce4d == '\0') && (DAT_ffffce49 == '\x01')) {
    DAT_ffffce3c = 0;
    puVar2 = (undefined4 *)0x1;
  }
  else {
    puVar2 = (undefined4 *)(uint)engine_running_ffffa428;
    if (puVar2 == (undefined4 *)0x1) {
      fVar3 = rx8_max_float(fVar3,arg1);
      fVar3 = rx8_min_float(fVar3,3.6e+07);
      fVar3 = fVar3 / 32.0;
      puVar2 = &DAT_0004ba34;
      if (2.1474836e+09 < fVar3) {
        puVar2 = &DAT_0004ba38;
        fVar3 = fVar3 + -4.2949673e+09;
      }
      DAT_ffffce3c = (int)fVar3;
    }
  }
  DAT_ffffce4d = cVar1;
  return puVar2;
}



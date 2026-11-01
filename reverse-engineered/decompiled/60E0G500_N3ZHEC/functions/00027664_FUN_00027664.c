/* ROM address: 0x00027664; body bytes: 100; decompiled */

undefined2 * FUN_00027664(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float fVar2;
  
  if (DAT_ffffbb04 == 400) {
    fVar2 = rx8_max_float((float)DAT_ffffcbe4,(float)DAT_ffffcbe8);
    DAT_ffffb700 = (undefined2)(int)fVar2;
  }
  puVar1 = &DAT_ffffbb06;
  if (DAT_ffffbb06 == 2000) {
    fVar2 = rx8_max_float((float)DAT_ffffcbe6,(float)DAT_ffffcbea);
    DAT_ffffb702 = (undefined2)(int)fVar2;
    puVar1 = extraout_r0;
  }
  return puVar1;
}



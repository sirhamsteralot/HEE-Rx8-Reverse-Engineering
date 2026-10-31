/* ROM address: 0x000384a2; body bytes: 60; decompiled */

undefined4 * FUN_000384a2(void)

{
  undefined4 *puVar1;
  float fVar2;
  
  puVar1 = (undefined4 *)&DAT_0007a7f4;
  if (0x49 < DAT_ffffc4f8) {
    fVar2 = rx8_max_float(DAT_ffffc4e8 * 0.099999994,1.0);
    fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffc4ec,fVar2);
    puVar1 = &DAT_00038554;
    DAT_ffffc4e4 = fVar2 * 100.0;
  }
  return puVar1;
}



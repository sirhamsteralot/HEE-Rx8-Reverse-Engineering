/* ROM address: 0x000176ba; body bytes: 154; decompiled */

undefined2 * FUN_000176ba(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float fVar2;
  
  puVar1 = &DAT_00078e5a;
  if (((DAT_ffffa426 < 0x1e) || (DAT_ffffa930 != 0)) || (1800.0 < DAT_ffffa910)) {
    DAT_ffffa8ec = 0.0;
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffa8f8,DAT_ffffa8fc);
    fVar2 = rx8_max_float(fVar2,DAT_ffffa904);
    DAT_ffffa8ec = rx8_min_float(fVar2,50.0);
    puVar1 = extraout_r0;
  }
  if ((DAT_ffffa8ec != 0.0) || (DAT_ffffa944 <= 0.0)) {
    if (DAT_ffffa930 != 0) {
      DAT_ffffa930 = DAT_ffffa930 + -1;
    }
  }
  else {
    DAT_ffffa930 = 0x4e2;
  }
  DAT_ffffa944 = DAT_ffffa8ec;
  return puVar1;
}



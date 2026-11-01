/* ROM address: 0x00018ef8; body bytes: 82; decompiled */

void FUN_00018ef8(void)

{
  float arg1;
  
  if (DAT_ffffa9bc == 0) {
    DAT_ffffa9b8 = 0.0;
  }
  else {
    DAT_ffffa9c4 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,&DAT_00069c44);
    DAT_ffffa9c8 = DAT_ffffbd0c - DAT_ffffa9c4;
    arg1 = rx8_max_float(DAT_ffffa9b0,DAT_ffffa9b4);
    DAT_ffffa9b8 = rx8_min_float(DAT_ffffa9c8,arg1);
  }
  return;
}



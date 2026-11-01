/* ROM address: 0x00017278; body bytes: 420; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000173a8) */

undefined2 * FUN_00017278(void)

{
  undefined2 *puVar1;
  float fVar2;
  
  if ((((((DAT_ffffa426 < 0x1f) || (DAT_ffffaa10 <= 255.0)) || (DAT_ffffae54 <= 255.0)) ||
       ((80.0 <= DAT_ffffae54 || (2.0 <= DAT_ffffbc1c)))) ||
      ((DAT_ffffad8c <= 82.0 || ((DAT_ffffa94c < 0xfa || (DAT_ffffa7c4 != '\x01')))))) ||
     ((0x10 < DAT_ffffa939 || ((DAT_ffffb5ac != '\x01' && (DAT_ffffb5aa != '\x01')))))) {
    DAT_ffffa93c = '\0';
  }
  else {
    DAT_ffffa93c = '\x01';
  }
  fVar2 = DAT_ffffa7b8;
  if (DAT_ffffa7c4 == '\x01') {
    DAT_ffffa94c = FUN_00002460((int)(short)DAT_ffffa94c,1);
  }
  else {
    DAT_ffffa94c = 0;
  }
  DAT_ffffa8f4 = rx8_first_order_filter(DAT_ffffa89c + fVar2,DAT_ffffa8f4,0.1,1e-05);
  if ((DAT_ffffa93c != '\x01') || (DAT_ffffa8f4 <= 0.12)) {
    DAT_ffffa93d = 0;
    DAT_ffffa94e = 0;
  }
  else {
    DAT_ffffa93d = 0x270 < DAT_ffffa94e;
    DAT_ffffa94e = FUN_00002460((int)(short)DAT_ffffa94e,1);
  }
  if ((DAT_ffffa93d == 1) && (DAT_ffffa95e == '\0')) {
    DAT_ffffa956 = 0;
  }
  else {
    DAT_ffffa956 = FUN_00002460((int)(short)DAT_ffffa956,1);
  }
  puVar1 = (undefined2 *)(uint)DAT_ffffa93d;
  if ((puVar1 == (undefined2 *)&UNK_00000001) && (puVar1 = &DAT_00078e50, DAT_ffffa956 < 0x1b6)) {
    DAT_ffffa8f8 = 30.0;
  }
  else {
    DAT_ffffa8f8 = DAT_ffffa8f8 - 0.048;
    if (DAT_ffffa8f8 < 0.0) {
      DAT_ffffa8f8 = 0.0;
    }
  }
  DAT_ffffa95e = DAT_ffffa93d;
  return puVar1;
}



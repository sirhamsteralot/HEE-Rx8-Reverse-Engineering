/* ROM address: 0x00019cfe; body bytes: 42; decompiled */

void FUN_00019cfe(void)

{
  if (DAT_ffffa428 == '\0') {
    DAT_ffffaa1c = rx8_first_order_filter(DAT_ffffaa10,DAT_ffffaa1c,0.75,1e-05);
  }
  return;
}



/* ROM address: 0x0003de9c; body bytes: 50; decompiled */

void FUN_0003de9c(void)

{
  float arg1;
  
  if (DAT_ffffd1e9 == '\0') {
    arg1 = DAT_ffffaa10;
    DAT_ffffc660 = rx8_max_float(DAT_ffffc660,DAT_ffffaa10);
    DAT_ffffc664 = rx8_min_float(DAT_ffffc664,arg1);
  }
  return;
}



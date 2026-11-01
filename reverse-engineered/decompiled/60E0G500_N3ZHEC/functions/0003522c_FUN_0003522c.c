/* ROM address: 0x0003522c; body bytes: 116; decompiled */

undefined2 * FUN_0003522c(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  
  DAT_ffffc1b8 = DAT_ffffc198 * DAT_ffffc1a4 + DAT_ffffc184 * DAT_ffffc1a8 * DAT_ffffc1b4 +
                 DAT_ffffc188 * DAT_ffffc194;
  puVar1 = &DAT_ffffa426;
  if ((DAT_ffffa426 == 0) ||
     ((DAT_ffffc17c == '\x01' && (puVar1 = (undefined2 *)0x1, 0.03125 <= DAT_ffffc084)))) {
    DAT_ffffc178 = 0.0;
  }
  else {
    DAT_ffffc178 = rx8_min_float(DAT_ffffc180 * DAT_ffffc1b8,16.0);
    puVar1 = extraout_r0;
  }
  return puVar1;
}



/* ROM address: 0x00034d94; body bytes: 106; decompiled */

undefined2 * FUN_00034d94(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  
  DAT_ffffc144 = DAT_ffffc158 * DAT_ffffc164 + DAT_ffffc148 * DAT_ffffc154 +
                 DAT_ffffc168 * DAT_ffffc174;
  puVar1 = &DAT_ffffa426;
  if ((DAT_ffffa426 == 0) ||
     ((DAT_ffffc17c == '\x01' && (puVar1 = (undefined2 *)0x1, DAT_ffffb5b8 < 812.5)))) {
    DAT_ffffc140 = 0.0;
  }
  else {
    DAT_ffffc140 = rx8_min_float(DAT_ffffc144,16.0);
    puVar1 = extraout_r0;
  }
  return puVar1;
}



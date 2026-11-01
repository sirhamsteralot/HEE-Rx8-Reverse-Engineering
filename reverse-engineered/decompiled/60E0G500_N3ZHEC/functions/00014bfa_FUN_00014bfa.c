/* ROM address: 0x00014bfa; body bytes: 250; decompiled */

undefined2 * FUN_00014bfa(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffa833 == DAT_ffffbdd5) {
    if (DAT_ffffa81c != 0) {
      DAT_ffffa81c = DAT_ffffa81c + -1;
    }
  }
  else {
    DAT_ffffa81c = 0x1f;
  }
  if (DAT_ffffa834 == DAT_ffffb5ac) {
    if (DAT_ffffa81e != 0) {
      DAT_ffffa81e = DAT_ffffa81e + -1;
    }
  }
  else {
    DAT_ffffa81e = 0x1f;
  }
  if ((DAT_ffffad90 == '\x01') && (DAT_ffffa835 == '\0')) {
    DAT_ffffa820 = 0xc;
  }
  else if (DAT_ffffa820 != 0) {
    DAT_ffffa820 = DAT_ffffa820 + -1;
  }
  if ((DAT_ffffad90 == '\0') && (DAT_ffffa835 == '\x01')) {
    DAT_ffffa822 = 0x5c;
    puVar1 = (undefined2 *)&UNK_00000001;
  }
  else {
    puVar1 = (undefined2 *)(int)DAT_ffffa822;
    if (puVar1 != (undefined2 *)0x0) {
      DAT_ffffa822 = DAT_ffffa822 + -1;
    }
  }
  if ((((DAT_ffffa81c == 0) && (DAT_ffffa81e == 0)) &&
      (puVar1 = (undefined2 *)(int)DAT_ffffa820, puVar1 == (undefined2 *)0x0)) &&
     (puVar1 = &DAT_ffffa822, DAT_ffffa822 == 0)) {
    DAT_ffffa7c5 = 0;
  }
  else {
    DAT_ffffa7c5 = 1;
  }
  DAT_ffffa833 = DAT_ffffbdd5;
  DAT_ffffa834 = DAT_ffffb5ac;
  DAT_ffffa835 = DAT_ffffad90;
  return puVar1;
}



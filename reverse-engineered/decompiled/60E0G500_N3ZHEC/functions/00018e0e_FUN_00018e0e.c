/* ROM address: 0x00018e0e; body bytes: 92; decompiled */

void FUN_00018e0e(void)

{
  DAT_ffffa9d0 = DAT_ffffa9bc;
  if (((DAT_ffffa9bc != 0) || (DAT_ffffa9be != 0)) ||
     ((DAT_ffffa9b0 <= 0.0 && (DAT_ffffa9b4 <= 0.0)))) {
    if (DAT_ffffa9bc != 0) {
      DAT_ffffa9bc = DAT_ffffa9bc + -1;
    }
  }
  else {
    DAT_ffffa9bc = FUN_0000213c(DAT_ffffb5b8,DAT_ffffc12c,&DAT_00069cb4);
  }
  return;
}



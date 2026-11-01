/* ROM address: 0x00034b12; body bytes: 126; decompiled */

undefined4 FUN_00034b12(void)

{
  char cVar1;
  undefined4 extraout_r0;
  undefined4 uVar2;
  float arg0;
  
  cVar1 = DAT_ffffa42c;
  if ((DAT_ffffa41c == '\x01') || ((DAT_ffffc13d == '\0' && (DAT_ffffa42c == '\x01')))) {
    uVar2 = 1;
    DAT_ffffc12c = 0.525;
  }
  else {
    if (DAT_ffffc13c == '\0') {
      arg0 = rx8_first_order_filter(DAT_ffffc128,DAT_ffffc12c,0.2,1e-05);
    }
    else {
      arg0 = rx8_first_order_filter(DAT_ffffc128,DAT_ffffc12c,1.0,1e-05);
    }
    DAT_ffffc12c = rx8_min_float(arg0,DAT_ffffc130);
    uVar2 = extraout_r0;
  }
  DAT_ffffc13d = cVar1;
  return uVar2;
}



/* ROM address: 0x0003f7ee; body bytes: 120; decompiled */

void FUN_0003f7ee(void)

{
  float fVar1;
  float fVar2;
  float arg1;
  
  if (DAT_ffffa428 == '\0') {
    if (DAT_ffffc6be == '\x01') {
      DAT_ffffc6b0 = DAT_ffffaa1c;
    }
    else {
      arg1 = DAT_ffffaa1c;
      fVar1 = (float)FUN_0003eb72(DAT_ffffaa1c,&DAT_ffff8730);
      fVar2 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
      DAT_ffffc6b0 = rx8_max_float(fVar1 - (fVar2 - arg1) * 10.0,arg1);
    }
  }
  else {
    DAT_ffffc6b0 = DAT_ffffc6b0 +
                   (DAT_ffffc6dc - DAT_ffffc6b0) * DAT_ffffc6c8 * DAT_ffffc6cc * DAT_ffffc6e4;
  }
  return;
}



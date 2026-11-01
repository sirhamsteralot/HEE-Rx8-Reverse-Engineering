/* ROM address: 0x0001e41e; body bytes: 140; decompiled */

void FUN_0001e41e(void)

{
  float arg0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffcb38 == '\x01') {
    DAT_ffffb120 = 0.65;
    DAT_ffffb124 = 0.0;
    DAT_ffffb128 = 0.0;
  }
  else {
    DAT_ffffb120 = 0.5;
    DAT_ffffb124 = (float)FUN_00002068(DAT_ffffbc1c,&DAT_0006a230);
    uVar1 = FUN_000024c0(0x41000000,uVar1,(int)DAT_ffffa424);
    DAT_ffffb128 = (float)FUN_00002068(uVar1,&DAT_0006a244);
  }
  arg0 = rx8_first_order_filter(DAT_ffffb120 + DAT_ffffb124 + DAT_ffffb128,DAT_ffffb0e8,1.0,1e-05);
  DAT_ffffb0e8 = rx8_clamp_float(arg0,0.0,1.0);
  return;
}



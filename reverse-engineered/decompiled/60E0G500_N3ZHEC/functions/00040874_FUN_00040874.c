/* ROM address: 0x00040874; body bytes: 180; decompiled */

uint FUN_00040874(void)

{
  short sVar1;
  short sVar2;
  uint extraout_r0;
  uint uVar3;
  float arg0;
  float arg0_00;
  float arg3;
  
  sVar2 = DAT_ffffae94;
  sVar1 = DAT_ffffae92;
  arg3 = 1e-05;
  arg0 = DAT_ffffaae4;
  arg0_00 = DAT_ffffae64;
  DAT_ffffc778 = rx8_first_order_filter(DAT_ffffaae4,DAT_ffffc778,1.0,1e-05);
  DAT_ffffc77c = rx8_first_order_filter(arg0,DAT_ffffc77c,0.5,arg3);
  DAT_ffffc780 = rx8_first_order_filter(arg0_00,DAT_ffffc780,0.1,arg3);
  DAT_ffffc784 = rx8_first_order_filter(arg0_00,DAT_ffffc784,0.03125,arg3);
  uVar3 = extraout_r0;
  if ((sVar2 == 0) && (uVar3 = (uint)DAT_ffffc970, uVar3 == 1)) {
    DAT_ffffc976 = 1;
  }
  if ((sVar1 == 0) && (uVar3 = (uint)DAT_ffffc972, uVar3 == 1)) {
    DAT_ffffc977 = 1;
  }
  DAT_ffffc970 = sVar2;
  DAT_ffffc972 = sVar1;
  return uVar3;
}



/* ROM address: 0x0004aafe; body bytes: 84; decompiled */

uint FUN_0004aafe(void)

{
  uint uVar1;
  
  DAT_ffffcdf2 = DAT_ffffcdca;
  uVar1 = (uint)DAT_ffffcddc;
  if (uVar1 == 1) {
    DAT_ffffcdb8 = rx8_first_order_filter(DAT_ffffb0e4,DAT_ffffcdb8,0.03,1e-05);
    DAT_ffffcdc8 = FUN_00002460((int)DAT_ffffcdc8,1);
    uVar1 = FUN_00002460((int)DAT_ffffcdca,1);
    DAT_ffffcdca = (short)uVar1;
  }
  else {
    DAT_ffffcdca = 0;
  }
  return uVar1;
}



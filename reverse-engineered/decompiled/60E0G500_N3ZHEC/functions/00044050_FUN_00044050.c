/* ROM address: 0x00044050; body bytes: 136; decompiled */

void FUN_00044050(void)

{
  float fVar1;
  
  if (0.5 <= DAT_ffffca78) {
    if (1.5 <= DAT_ffffca78) {
      DAT_ffffca6c = (DAT_ffffcad0 + DAT_ffffcad4 + DAT_ffffcad8 + DAT_ffffca70) / 4.0;
    }
    else {
      DAT_ffffca6c = (DAT_ffffcad0 + DAT_ffffca70) / 2.0;
    }
  }
  else {
    DAT_ffffca6c = DAT_ffffca70;
  }
  fVar1 = DAT_ffffca70;
  DAT_ffffca68 = rx8_first_order_filter(DAT_ffffca6c,DAT_ffffca68,1.0 - DAT_ffffca8c,1e-05);
  DAT_ffffcad8 = DAT_ffffcad4;
  DAT_ffffcad4 = DAT_ffffcad0;
  DAT_ffffcad0 = fVar1;
  return;
}



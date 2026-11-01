/* ROM address: 0x00044884; body bytes: 126; decompiled */

uint cranking_timing_leading_filter(void)

{
  byte bVar1;
  uint uVar2;
  uint extraout_r0;
  float fVar3;
  float extraout_fr0;
  
  bVar1 = DAT_ffffb5ac;
  uVar2 = (uint)DAT_ffffaada;
  if ((uVar2 == 1) && (uVar2 = (uint)DAT_ffffb5ac, uVar2 == 1)) {
    DAT_ffffcb14 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b9d0);
    if (DAT_ffffcb1c == '\0') {
      fVar3 = rx8_min_float(1.0,1.0);
      uVar2 = FUN_0003ea74(DAT_ffffcb14,fVar3);
      DAT_ffffcb0c = extraout_fr0;
    }
    else {
      DAT_ffffcb0c = rx8_first_order_filter(DAT_ffffcb14,DAT_ffffcb0c,1.0,1e-05);
      uVar2 = extraout_r0;
    }
  }
  else {
    DAT_ffffcb14 = 0.0;
    DAT_ffffcb0c = 0.0;
  }
  DAT_ffffcb1c = bVar1;
  return uVar2;
}



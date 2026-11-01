/* ROM address: 0x0001f5ac; body bytes: 106; decompiled */

undefined4 FUN_0001f5ac(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff80ec + (uint)DAT_ffffb16e * 8);
  fVar3 = rx8_absolute_difference(DAT_ffffb140,fVar2);
  uVar1 = extraout_r0;
  if ((0.02 <= fVar3) && (uVar1 = 1, DAT_ffffa41c != '\x01')) {
    fVar2 = rx8_first_order_filter(fVar2,DAT_ffffb140,0.1,1e-05);
    fVar2 = rx8_clamp_float(fVar2,-0.23,0.23);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffb140 = fVar2;
  return uVar1;
}



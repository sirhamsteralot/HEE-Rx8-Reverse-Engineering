/* ROM address: 0x00029ed0; body bytes: 120; decompiled */

undefined4 * can201_prepare_rpm_with_conditional_filter(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  float fVar2;
  float fVar3;
  float arg0;
  
  arg0 = DAT_ffffb5b8;
  fVar2 = rx8_absolute_difference(DAT_ffffb5b8,DAT_ffffbb70);
  puVar1 = &DAT_00029f8c;
  fVar3 = arg0;
  if ((((DAT_ffffbc1c <= 0.099999994) &&
       (puVar1 = (undefined4 *)(uint)DAT_ffffa428, puVar1 == (undefined4 *)0x1)) &&
      (puVar1 = (undefined4 *)(uint)DAT_ffffaada, puVar1 == (undefined4 *)0x1)) &&
     ((arg0 < DAT_ffffa7bc + 150.0 && (fVar2 < 30.0)))) {
    fVar3 = rx8_first_order_filter(arg0,DAT_ffffbb6c,0.04,1e-05);
    puVar1 = extraout_r0;
  }
  DAT_ffffbb6c = fVar3;
  DAT_ffffbb70 = arg0;
  return puVar1;
}



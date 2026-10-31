/* ROM address: 0x0004bab4; body bytes: 342; decompiled */

undefined ** FUN_0004bab4(void)

{
  uint uVar1;
  undefined **ppuVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float arg1;
  float arg0;
  
  arg1 = inferred_coolant_temperature_ffffa98c;
  fVar5 = intake_air_temperature_ffffaddc;
  arg0 = DAT_ffffce34;
  fVar3 = rx8_max_float(intake_air_temperature_ffffaddc,5.0);
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar3,&DAT_ffff8774);
  fVar4 = rx8_absolute_difference(arg0,arg1);
  fVar5 = rx8_absolute_difference(fVar3,fVar5);
  if (arg1 <= -10.0) {
    uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8770,4);
  }
  else {
    uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8770,0);
  }
  ppuVar2 = (undefined **)(uint)engine_stopped_latch_ffffa41c;
  if (ppuVar2 != (undefined **)((int)&vector_Poweron_Reset + 1)) {
    return ppuVar2;
  }
  if ((arg0 < -10.0) &&
     (ppuVar2 = (undefined **)(uVar1 & 0xff),
     ppuVar2 == (undefined **)((int)&vector_Poweron_Reset + 1))) {
    DAT_ffffce48 = 1;
    goto LAB_0004bc4c;
  }
  if ((arg0 < -10.0) &&
     (ppuVar2 = (undefined **)(uVar1 & 0xff),
     ppuVar2 == (undefined **)((int)&vector_Poweron_Reset + 2))) {
    DAT_ffffce48 = 2;
    goto LAB_0004bc4c;
  }
  if ((1.875 <= fVar4) || (1.875 <= fVar5)) {
LAB_0004bc18:
    if ((arg0 < -5.0) &&
       (ppuVar2 = (undefined **)(uVar1 & 0xff),
       ppuVar2 == (undefined **)((int)&vector_Poweron_Reset + 3))) {
      DAT_ffffce48 = 4;
      goto LAB_0004bc4c;
    }
  }
  else {
    ppuVar2 = (undefined **)&DAT_0000493e;
    if ((DAT_ffffce40 < &DAT_0000493e) &&
       (((ppuVar2 = (undefined **)&DAT_0007d008, DAT_ffffce44 < 10 && (arg0 < -5.0)) &&
        (ppuVar2 = (undefined **)(uVar1 & 0xff),
        ppuVar2 == (undefined **)((int)&vector_Poweron_Reset + 3))))) {
      DAT_ffffce48 = 3;
      goto LAB_0004bc4c;
    }
    if (((1.875 <= fVar4) || (1.875 <= fVar5)) ||
       ((ppuVar2 = &PTR_DAT_0007d018, (undefined *)((int)&DAT_0000493c + 1) < DAT_ffffce40 ||
        (ppuVar2 = (undefined **)&DAT_0007d008, 9 < DAT_ffffce44)))) goto LAB_0004bc18;
  }
  if ((-5.0 <= arg0) ||
     (ppuVar2 = (undefined **)(uVar1 & 0xff), ppuVar2 != (undefined **)&UNK_00000004)) {
    DAT_ffffce48 = 0;
    return ppuVar2;
  }
  DAT_ffffce48 = 5;
LAB_0004bc4c:
  return (undefined **)(uVar1 & 0xff);
}



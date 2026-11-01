/* ROM address: 0x0001ecee; body bytes: 240; decompiled */

undefined4 FUN_0001ecee(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float extraout_fr0;
  float fVar4;
  float fVar5;
  
  cVar1 = DAT_ffffcac8;
  fVar5 = 0.0;
  if (DAT_ffffb108 == '\0') {
    DAT_ffffb110 = 0;
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff80fc);
    fVar4 = fVar5;
  }
  else {
    DAT_ffffb110 = rx8_add_u16_saturate((int)(short)DAT_ffffb110,1);
    fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar5,&DAT_ffff80fc);
    fVar3 = inferred_trim_b074_ffffb074_ffffb074 + fVar3;
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar3,&DAT_ffff80fc);
    fVar4 = fVar5;
    if (DAT_ffffb110 != 0) {
      uVar2 = rx8_decode_u16_affine(0x3f800000,fVar5,(int)(short)DAT_ffffb110);
      fVar4 = fVar3 / extraout_fr0;
    }
  }
  DAT_ffffb10c = fVar4;
  if (0x1ff < DAT_ffffb110) {
    DAT_ffffb110 = 0;
    fVar4 = rx8_clamp_float(DAT_ffffb10c,-0.01,0.01);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff80ec);
    DAT_ffffb10c = fVar5;
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar5,&DAT_ffff80fc);
  }
  if (cVar1 != DAT_ffffb117) {
    DAT_ffffb110 = 0;
    if (cVar1 == '\x01') {
      uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(fVar5,&DAT_ffff80ec);
      fVar4 = fVar5;
      ref_updateMemoryAtAddress_float_VAL_ADDR(uVar2,&DAT_ffff80f4);
      fVar5 = fVar4;
    }
    else {
      fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar5,&DAT_ffff80f4);
    }
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff80ec);
    DAT_ffffb10c = fVar5;
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar5,&DAT_ffff80fc);
  }
  DAT_ffffb117 = cVar1;
  return uVar2;
}



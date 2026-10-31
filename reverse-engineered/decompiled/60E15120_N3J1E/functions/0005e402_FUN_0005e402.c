/* ROM address: 0x0005e402; body bytes: 114; decompiled */

uint FUN_0005e402(void)

{
  uint uVar1;
  float arg1;
  float arg2;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffd252;
  fVar2 = (DAT_ffffadec + DAT_ffffb0d0 + -1.0) * 100.0;
  if (uVar1 == 0x30) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff9160);
    return uVar1;
  }
  if (uVar1 == 0x40) {
    arg2 = 0.004999995;
    arg1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff9160);
    fVar2 = rx8_first_order_filter(fVar2,arg1,arg2,1e-05);
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff9160);
    return uVar1;
  }
  return uVar1;
}



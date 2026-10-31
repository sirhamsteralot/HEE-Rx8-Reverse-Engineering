/* ROM address: 0x0001e900; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001f360 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_LTFTForCAN__(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80c4 + (uint)maf_range_index_ffffb0fe * 8);
  fVar3 = rx8_absolute_difference(DAT_ffffb0d0,fVar2);
  uVar1 = extraout_r0;
  if ((0.02 <= fVar3) && (uVar1 = 1, engine_stopped_latch_ffffa41c != '\x01')) {
    fVar2 = rx8_first_order_filter(fVar2,DAT_ffffb0d0,0.1,1e-05);
    fVar2 = rx8_clamp_float(fVar2,-0.23,0.23);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffb0d0 = fVar2;
  return uVar1;
}



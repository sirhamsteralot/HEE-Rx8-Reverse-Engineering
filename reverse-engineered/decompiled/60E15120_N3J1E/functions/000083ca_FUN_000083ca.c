/* ROM address: 0x000083ca; body bytes: 184; decompiled */

void FUN_000083ca(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  iVar3 = (param_1 & 0xff) * 0x18;
  *(int *)(&DAT_ffffa004 + iVar3) = param_3;
  iVar2 = ref_LongFunc((&injector_zero_offset_ch0_ffffa0ac)[param_1 & 0xff] + *(int *)(&DAT_ffffa004 + iVar3) +
                       (&injector_latency_ch0_ffffa094)[param_1 & 0xff],crank_period_accumulator_ffff9f88);
  *(int *)(&DAT_ffffa00c + iVar3) = iVar2 * 0xb4;
  param_2 = param_2 - (int)(DAT_ffff9f98 * 65536.0);
  if (param_2 < -0x3c0000) {
    param_2 = param_2 + 0x2d00000;
  }
  else if (0x293ffff < param_2) {
    param_2 = param_2 + -0x2d00000;
  }
  *(int *)(&DAT_ffffa008 + iVar3) = param_2 - *(int *)(&DAT_ffffa00c + iVar3);
  (&injector_channel_enable_flag_ffffa017)[iVar3] = 2;
  if (*(int *)(&DAT_ffffa008 + iVar3) < 0x230000) {
    FUN_00008814(param_1);
    (&injector_channel_enable_flag_ffffa017)[iVar3] = 0;
  }
  ref_setSR(uVar1);
  return;
}



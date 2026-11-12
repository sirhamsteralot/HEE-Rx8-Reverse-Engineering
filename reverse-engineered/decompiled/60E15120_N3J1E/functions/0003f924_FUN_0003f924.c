/* [ADDITIONAL SOURCE REVIEW]
 * o2_channel_filter_update [high]: First-order filters (epsilon 1e-5) of diag AFR word 0xffffaa6c (factors 1.0 -> 0xffffc708, 0.5 -> 0xffffc70c) and actual lambda 0xffffadec (0.1 -> 0xffffc710, 0.03125 -> 0xffffc714); latches 0xffffc900/0xffffc902 edges from 0xffffae1a/ae1c. Feeds 0x3fb9e. Called from 0x38dca (pool-verified jsr).
 * RAM 0xffffc708 o2_channel_afr_fast (float): First-order filtered diag AFR word 0xffffaa6c, factor 1.0 (0x3f800000); snapshot input to 0x3fb9e.
 * RAM 0xffffc70c o2_channel_afr_medium (float): Second AFR-word channel: first_order_filter(diag_afr_word_a 0xffffaa6c, 0xffffc70c, 0.5, 1e-5) in o2_channel_filter_update 0x3f924; delta-accumulated in 0x3fb9e (c768/c774 vs c8f0) into ratio channels ch2/ch3 (0xffffc780/c784).
 * RAM 0xffffc714 o2_channel_lambda_very_slow (float): Slowest lambda channel: first_order_filter(inferred_lambda_actual_ffffadec 0xffffadec, 0xffffc714, 0.03125, 1e-5) in 0x3f924; ring 0xffffc870 + deltas c738/c744 vs c8f8 into ratio channels ch2/ch3.
 */
/* ROM address: 0x0003f924; body bytes: 180; decompiled */

uint o2_channel_filter_update(void)

{
  short sVar1;
  short sVar2;
  uint extraout_r0;
  uint uVar3;
  float arg0;
  float arg0_00;
  float arg3;
  
  sVar2 = DAT_ffffae1c;
  sVar1 = DAT_ffffae1a;
  arg3 = 1e-05;
  arg0 = diag_afr_word_a_ffffaa6c;
  arg0_00 = inferred_lambda_actual_ffffadec_ffffadec;
  o2_channel_afr_fast_ffffc708 = rx8_first_order_filter(diag_afr_word_a_ffffaa6c,o2_channel_afr_fast_ffffc708,1.0,1e-05);
  o2_channel_afr_medium_ffffc70c = rx8_first_order_filter(arg0,o2_channel_afr_medium_ffffc70c,0.5,arg3);
  o2_channel_lambda_slow_ffffc710 = rx8_first_order_filter(arg0_00,o2_channel_lambda_slow_ffffc710,0.1,arg3);
  o2_channel_lambda_very_slow_ffffc714 = rx8_first_order_filter(arg0_00,o2_channel_lambda_very_slow_ffffc714,0.03125,arg3);
  uVar3 = extraout_r0;
  if ((sVar2 == 0) && (uVar3 = (uint)DAT_ffffc900, uVar3 == 1)) {
    DAT_ffffc906 = 1;
  }
  if ((sVar1 == 0) && (uVar3 = (uint)DAT_ffffc902, uVar3 == 1)) {
    DAT_ffffc907 = 1;
  }
  DAT_ffffc900 = sVar2;
  DAT_ffffc902 = sVar1;
  return uVar3;
}



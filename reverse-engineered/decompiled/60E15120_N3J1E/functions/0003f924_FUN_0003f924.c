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
  DAT_ffffc70c = rx8_first_order_filter(arg0,DAT_ffffc70c,0.5,arg3);
  o2_channel_lambda_slow_ffffc710 = rx8_first_order_filter(arg0_00,o2_channel_lambda_slow_ffffc710,0.1,arg3);
  DAT_ffffc714 = rx8_first_order_filter(arg0_00,DAT_ffffc714,0.03125,arg3);
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



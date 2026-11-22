/* [ADDITIONAL SOURCE REVIEW]
 * throttle_base_position_filter [high]: b390 = first_order_filter(b38c, b390, 0.25, 1e-5); b394 = (b38c <= 2.0). Called from batch 0x22f86.
 */
/* ROM address: 0x00022d26; body bytes: 58; decompiled */

undefined4 throttle_base_position_filter(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffb390 = rx8_first_order_filter(candidate_throttle_base_position_ffffb38c,DAT_ffffb390,0.25,1e-05);
  uVar1 = extraout_r0;
  if (candidate_throttle_base_position_ffffb38c <= 2.0) {
    uVar1 = 1;
  }
  DAT_ffffb394 = candidate_throttle_base_position_ffffb38c <= 2.0;
  return uVar1;
}



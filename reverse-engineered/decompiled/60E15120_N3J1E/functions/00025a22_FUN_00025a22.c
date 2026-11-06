/* [ADDITIONAL SOURCE REVIEW]
 * charging_ok_latch [medium]: 0xffffb5b1 = (0xffffb60a == 0). Called from 0x267c6 via pool 0x2688c.
 * RAM 0xffffb5b1 charging_ok_latch (uint8): Set by 0x25a22 = (0xffffb60a == 0), i.e. P2502 confirmation timer fully counted down; gates P2502 raise in 0x545bc and the warning flag in 0x26760.
 */
/* ROM address: 0x00025a22; body bytes: 26; decompiled */

void candidate_charging_ok_latch(void)

{
  charging_ok_latch_ffffb5b1 = DAT_ffffb60a == 0;
  return;
}



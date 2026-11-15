/* [ADDITIONAL SOURCE REVIEW]
 * key_off_early_counter_b [medium]: 0xffffb583 += 1 (pool 0x25390=0xffffb583); called from 0x253d0.
 * RAM 0xffffb583 key_off_early_counter_b (uint8): Incremented by 0x252b8 (pool 0x25390=0xffffb583).
 */
/* ROM address: 0x000252b8; body bytes: 10; decompiled */

void candidate_key_off_early_counter_b(void)

{
  key_off_early_counter_b_ffffb583 = key_off_early_counter_b_ffffb583 + '\x01';
  return;
}



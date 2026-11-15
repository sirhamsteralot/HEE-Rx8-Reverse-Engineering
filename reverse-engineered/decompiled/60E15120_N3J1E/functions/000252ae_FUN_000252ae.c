/* [ADDITIONAL SOURCE REVIEW]
 * key_off_early_counter_a [medium]: 0xffffb582 += 1 (pool 0x2538c=0xffffb582); called from 0x253b8; compared against 0xffffb583 in the early shutdown condition of 0x252c2.
 * RAM 0xffffb582 key_off_early_counter_a (uint8): Incremented by 0x252ae (pool 0x2538c=0xffffb582); compared with 0xffffb583 in the early shutdown condition of 0x252c2.
 */
/* ROM address: 0x000252ae; body bytes: 10; decompiled */

void candidate_key_off_early_counter_a(void)

{
  key_off_early_counter_a_ffffb582 = key_off_early_counter_a_ffffb582 + '\x01';
  return;
}



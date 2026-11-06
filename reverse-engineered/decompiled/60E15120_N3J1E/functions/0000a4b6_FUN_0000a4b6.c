/* [ADDITIONAL SOURCE REVIEW]
 * task12_alive_counter_clear [high]: 8-byte body: mov.w #0 -> 0xffffa188 (pool 0xa4d0); called only from task[12] 0x6592. Counter incremented in 0xa3ac, reset when > 300.
 */
/* ROM address: 0x0000a4b6; body bytes: 8; decompiled */

void task12_alive_counter_clear(void)

{
  task12_alive_counter_ffffa188 = 0;
  return;
}



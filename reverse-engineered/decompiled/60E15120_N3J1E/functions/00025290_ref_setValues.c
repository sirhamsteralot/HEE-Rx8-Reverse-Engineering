/* [ADDITIONAL SOURCE REVIEW]
 * key_off_state_init [high]: State init: 0xffffb57a = 0 (pool 0x25380=0xffffb57a), 0xffffb579 = 1 (pool 0x25374=0xb579); reached from init fan-out 0x1102a via 0x253ac.
 */
/* ROM address: 0x00025290; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025b18 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void key_off_state_init(void)

{
  key_off_state_ffffb57a = 0;
  key_off_armed_flag_ffffb579 = 1;
  return;
}



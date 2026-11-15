/* [ADDITIONAL SOURCE REVIEW]
 * key_off_time_counter_update [high]: Was ref_calculateKeyOffTime: 0xffffa9e2 saturating ++ while 0xffffaa68 == 0 (pools 0x1961e=0xa9e2, 0x1961c=0xaa68, 0x19620=0x2460); called from 0x199d4.
 * RAM 0xffffa9e2 key_off_time_counter (uint16): Saturating u16 key-off time, ++ while 0xffffaa68 == 0 (0x195f4; pools 0x1961e=0xa9e2, 0x1961c=0xaa68, 0x19620=0x2460).
 */
/* ROM address: 0x000195f4; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001a310 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void key_off_time_counter_update(void)

{
  if (engine_running_flag_ffffaa68 == '\0') {
    key_off_time_counter_ffffa9e2 = rx8_add_u16_saturate((int)key_off_time_counter_ffffa9e2,1);
  }
  else {
    key_off_time_counter_ffffa9e2 = 0;
  }
  return;
}



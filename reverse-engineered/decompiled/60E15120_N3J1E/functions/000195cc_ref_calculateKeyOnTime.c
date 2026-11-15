/* [ADDITIONAL SOURCE REVIEW]
 * key_on_time_counter_update [high]: Was ref_calculateKeyOnTime: if engine flag 0xffffaa68 == 1 (pool 0x1961c=0xaa68) then 0xffffa9e0 = saturate(0xffffa9e0 + 1) via 0x2460 (pools 0x1961a=0xa9e0, 0x19620=0x2460), else 0; called from 0x199d4.
 * RAM 0xffffa9e0 key_on_time_counter (uint16): Saturating u16 key-on time, ++ while 0xffffaa68 == 1 (0x195cc; pools 0x1961a=0xa9e0, 0x1961c=0xaa68, 0x19620=0x2460).
 */
/* ROM address: 0x000195cc; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001a2e8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint key_on_time_counter_update(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_running_flag_ffffaa68;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)key_on_time_counter_ffffa9e0,1);
    key_on_time_counter_ffffa9e0 = (short)uVar1;
  }
  else {
    key_on_time_counter_ffffa9e0 = 0;
  }
  return uVar1;
}



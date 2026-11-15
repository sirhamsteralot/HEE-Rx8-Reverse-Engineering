/* [ADDITIONAL SOURCE REVIEW]
 * key_input_pf15_sample [high]: Reads PFDR_W (pool 0x45508=0xf74e), stores 0xffffcbd1 = (PFDR & 0x8000) == 0 (mask pool 0x4550c=0x8000, cell pool 0x45510=0xffffcbd1); called from 0x19640. PF15 is a second key-related input pin.
 * RAM 0xffffcbd1 key_input_pf15_prev (uint8): Previous PF15 sample: (PFDR_W & 0x8000) == 0 stored by 0x454c0 (pool 0x45510=0xffffcbd1).
 */
/* ROM address: 0x000454c0; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004454c (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void key_input_pf15_sample(void)

{
  ushort uVar1;
  
  uVar1 = PFDR_W;
  key_input_pf15_prev_ffffcbd1 = (uVar1 & 0x8000) == 0;
  return;
}



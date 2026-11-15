/* [ADDITIONAL SOURCE REVIEW]
 * key_input_pf15_edge_latch [high]: Edge latch on PF15: reads PFDR_W & 0x8000 (pools 0x45508=0xf74e, 0x4550c=0x8000); on pin 1->0 sets 0xffffcbd0 = 1 (pool 0x4550a=0xcbd0), on 0->1 clears it; keeps 0xffffcbd1 (pool 0x45510) as previous sample; called from 0x199d4; consumed by 0x48d38 key_voltage_timer_update.
 * RAM 0xffffcbd0 key_input_pf15_edge_latch (uint8): Edge latch of PFDR_W 0xfffff74e bit 0x8000: set 1 on pin 1->0, cleared on 0->1 by 0x454d2 (pools 0x4550a=0xcbd0, 0x45508=0xf74e, 0x4550c=0x8000); read by 0x48d38.
 */
/* ROM address: 0x000454d2; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004455e (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

char key_input_pf15_edge_latch(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  
  uVar2 = PFDR_W;
  bVar1 = (uVar2 & 0x8000) == 0;
  if (bVar1) {
    cVar3 = key_input_pf15_prev_ffffcbd1;
    if (key_input_pf15_prev_ffffcbd1 == '\x01') {
      key_input_pf15_edge_latch_ffffcbd0 = 1;
    }
  }
  else {
    cVar3 = bVar1;
    if (key_input_pf15_prev_ffffcbd1 == '\0') {
      key_input_pf15_edge_latch_ffffcbd0 = 0;
    }
  }
  key_input_pf15_prev_ffffcbd1 = bVar1;
  return cVar3;
}



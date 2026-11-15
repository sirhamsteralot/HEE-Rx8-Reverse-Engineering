/* [ADDITIONAL SOURCE REVIEW]
 * key_on_latch_from_pfdr_bit0 [high]: 0xffffaa69 = (vehicle latch 0xffff9ec8 & 1) != 0: mov.l pool 0x1a610=0xffff9ec8, store pool 0x1a60c=0xffffaa69; called from 0x19640 and 0x19950. PFDR bit0 is the key-on (IG1) input sampled by 0x6744 vehicle_inputs_poll_pfdr_phdr.
 * RAM 0xffffaa69 key_on_latch_aa69 (uint8): = (0xffff9ec8 & 1) != 0 by 0x1a5d8 (pools 0x1a60c=0xffffaa69, 0x1a610=0xffff9ec8); copied to 0xffffaa68 by 0x1a600.
 */
/* ROM address: 0x0001a5d8; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b088 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool key_on_latch_from_pfdr_bit0(void)

{
  key_on_latch_aa69_ffffaa69 = (vehicle_inputs_pfdr_latch_ffff9ec8 & 1) != 0;
  return key_on_latch_aa69_ffffaa69;
}



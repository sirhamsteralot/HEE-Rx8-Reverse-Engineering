/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_write_thunk [medium]: 4-byte thunk calling the write area via register-indirect call; called from 0x35a8c (callgraph 0x35a8c -> 0x35d36). Inherited ref_writeToE2RAMAreaTHUNK confirmed.
 */
/* ROM address: 0x00035d36; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036456 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_e2ram_write_thunk(void)

{
  code *unaff_r14;
  
  (*unaff_r14)();
  return;
}



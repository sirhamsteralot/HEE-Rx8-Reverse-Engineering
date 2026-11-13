/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_shadow_byte_write_trampoline [high]: 14-byte body (words 4e0b 0009 4f26 6cf6 6df6 000b 6ef6 at 0x35d36, ROM-verified; byte-exact match with 60E0FC00 0x36456): `jsr @r14; nop; lds.l @r15+,pr; mov.l @r15+,r12; mov.l @r15+,r13; rts; mov.l @r15+,r14`. Sole caller 0x35a8c loads r14 exactly once, at 0x35a94 `mov.l @(0x35b74,pc),r14` with pool 0x35b74 = 0x00037ea4 (e2ram_shadow_byte_write), and all 14 dispatch arms `bra 0x35d36`; the epilogue pops the frame 0x35a8c pushed (r14/r13/r12/pr), so this is a tail-call trampoline to e2ram_shadow_byte_write 0x37ea4, not an unknown indirect call. Target proven -> promoted from candidate_ to a high-confidence label; inherited ref_writeToE2RAMAreaTHUNK_ was a misnomer (the real ref_writeToE2RAMArea_INDEX_ADDR_LEN is 0x37ea4).
 */
/* ROM address: 0x00035d36; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036456 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_shadow_byte_write_trampoline(void)

{
  code *unaff_r14;
  
  (*unaff_r14)();
  return;
}



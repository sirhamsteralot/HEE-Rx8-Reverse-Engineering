/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_bit08_check [medium]: 0xffffbbcf = ((0xffffbbde & 8) == 8). Called from 0x2a2ae via pool 0x2a474.
 * RAM 0xffffbbde can212_status_word (uint16): u16 from CAN 0x212 payload bytes 4-5 (0x2b7e2: bbc4*0x100+bbc5); bit 0x08 checked by 0x2b6a4 -> 0xffffbbcf.
 */
/* ROM address: 0x0002b6a4; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bdf8 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 candidate_dsc_mode_bit08_check(void)

{
  bool bVar1;
  undefined2 uVar2;
  
  bVar1 = (can212_status_word_ffffbbde & 8) != 8;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
  }
  DAT_ffffbbcf = !bVar1;
  return uVar2;
}



/* [ADDITIONAL SOURCE REVIEW]
 * rev_limit_fuel_cut_init [high]: When DAT_ffff9f8c == 1: clears rev-limit state a4a4/a4a5/a4a8.
 * RAM 0xffffa4a4 rev_limit_state_a (uint8): Cleared by rev_limit_fuel_cut_init (0xee64) when 9f8c==1.
 * RAM 0xffffa4a5 rev_limit_state_b (uint8): Cleared by 0xee64.
 * RAM 0xffffa4a8 rev_limit_state_c (uint8): Cleared by 0xee64.
 */
/* ROM address: 0x0000ee64; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ee68 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

char rev_limit_fuel_cut_init(void)

{
  if (DAT_ffff9f8c == '\x01') {
    rev_limit_state_a_ffffa4a4 = 0;
    rev_limit_state_b_ffffa4a5 = 0;
    rev_limit_state_c_ffffa4a8 = 0;
  }
  return DAT_ffff9f8c;
}



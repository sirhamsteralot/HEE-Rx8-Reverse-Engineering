/* [ADDITIONAL SOURCE REVIEW]
 * immo_compute_expected_key_words [high]: ref_immo_related__ (unique_exact_bytes to 60E0FC00 0x35a76). Computes c1dc/c1e0/c1e4/c1e8 = 0x35438 halves of (c26c,c270) scrambled with c208; c1f0..c1fc = those | tag 0x01..0x04 << 24. Dynamically observed: c1f0..c1fc = 0177b276/02c88dc9/037b7475/04c4cbca for the boot key state.
 * RAM 0xffffc1dc immo_computed_key_words (u32[4] c1dc-c1e8): raw scrambled words before the 0x01..0x04<<24 tag
 */
/* ROM address: 0x00035356; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035a76 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void immo_compute_expected_key_words(void)

{
  immo_computed_key_words_ffffc1dc = candidate_immo_key_word_scramble(immo_key_reg_b_ffffc270,immo_random_seed_ffffc208);
  DAT_ffffc1e0 = candidate_immo_key_word_scramble(immo_key_reg_b_ffffc270 >> 0x10,immo_random_seed_ffffc208 >> 8);
  DAT_ffffc1e4 = candidate_immo_key_word_scramble(immo_key_reg_a_ffffc26c,immo_random_seed_ffffc208 >> 0x10);
  DAT_ffffc1e8 = candidate_immo_key_word_scramble(immo_key_reg_a_ffffc26c >> 0x10,immo_random_seed_ffffc208 >> 0x18);
  immo_expected_key_words_ffffc1f0 = immo_computed_key_words_ffffc1dc | 0x1000000;
  DAT_ffffc1f4 = DAT_ffffc1e0 | 0x2000000;
  DAT_ffffc1f8 = DAT_ffffc1e4 | 0x3000000;
  DAT_ffffc1fc = DAT_ffffc1e8 | 0x4000000;
  return;
}



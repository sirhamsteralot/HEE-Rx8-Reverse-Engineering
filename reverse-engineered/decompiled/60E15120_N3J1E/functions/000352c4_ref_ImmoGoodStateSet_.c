/* [ADDITIONAL SOURCE REVIEW]
 * immo_set_authorized [high]: ref_ImmoGoodStateSet_ (unique_exact_bytes to 60E0FC00 0x359e4). Sets lamp on (0x2556c(1)), immo_authorized 0xffffc1d0=1, c282=2, c22f=1, c212=15000, c214=0xfa, c21c=0, c21d=3, c22a=0. Dynamically observed after a matching challenge.
 * RAM 0xffffc282 immo_registered_key_count (u8): c282==2 (or 1) admits the seed-request path with lamp on
 */
/* ROM address: 0x000352c4; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000359e4 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_ImmoGoodStateSet_(void)

{
  ref_setImmoLight__(1);
  inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 1;
  DAT_ffffc282 = 2;
  DAT_ffffc22f = 1;
  DAT_ffffc212 = 15000;
  DAT_ffffc214 = 0xfa;
  DAT_ffffc21c = 0;
  DAT_ffffc21d = 3;
  DAT_ffffc22a = 0;
  return;
}



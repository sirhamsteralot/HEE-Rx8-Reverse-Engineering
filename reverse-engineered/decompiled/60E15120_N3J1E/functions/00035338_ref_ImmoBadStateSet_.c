/* [ADDITIONAL SOURCE REVIEW]
 * immo_set_rejected [high]: ref_ImmoBadStateSet_ (unique_exact_bytes to 60E0FC00 0x35a58). Lamp off, 0xffffc1d0=0, c214=500, c21d=4. Dynamically observed after a wrong challenge.
 */
/* ROM address: 0x00035338; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035a58 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_ImmoBadStateSet_(void)

{
  ref_setImmoLight__(0);
  inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
  DAT_ffffc214 = 500;
  DAT_ffffc21d = 4;
  return;
}



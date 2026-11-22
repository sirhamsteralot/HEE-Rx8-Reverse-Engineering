/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_grace_eval [high]: Resets the run-on grace counter (mov.w r4,@r3 with r4=0, pool 0x2fcd8=0xffffbddc) and sets DAT_ffffbde0 = (DAT_ffffbdde > ROM[0x7bc5a]); the threshold is 0x0000 in this bin (pools 0x2fcf4=0x0007bc5a, 0x2fce4=0xffffbdde, 0x2fce8=0xffffbde0; cmp/hi r0,r2 at 0x2fcbc). Reached through 0x2f98c from 0x11b80.
 */
/* ROM address: 0x0002fcac; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00030164 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0002fcac(void)

{
  DAT_ffffbddc = 0;
  DAT_ffffbde0 = DAT_ffffbdde != 0;
  return DAT_ffffbdde != 0;
}



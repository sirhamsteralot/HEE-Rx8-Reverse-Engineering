/* [MATH AND UNITS REVIEW]
 * sh_busy_wait_count_times_8: Unsigned loop bound is input bits shifted left three modulo 2^32. No elapsed-time unit is established; do not call this delay_us without clock and instruction timing evidence.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000239c; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000239c (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sh_busy_wait_count_times_8(int delay_count)

{
  uint uVar1;
  
  uVar1 = 0;
  if (delay_count << 3 != 0) {
    do {
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(delay_count << 3));
  }
  return;
}



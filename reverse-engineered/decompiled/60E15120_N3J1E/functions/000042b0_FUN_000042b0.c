/* [MATH AND UNITS REVIEW]
 * sh_copy_bytes_forward_r0_r1_r2: Assembly ABI: R0=count, R1=destination, R2=source. Forward byte copy unrolled four times; zero count returns. Does not return original destination in R0 (R0 receives byte loads), so not a standard memcpy signature. No overlap-aware backwards path; do not call memmove. Looks like a runtime copy primitive, but compiler/library provenance is unproven.
 */
/* ROM address: 0x000042b0; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000042b0 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sh_copy_bytes_forward_r0_r1_r2(void)

{
  int in_r0;
  undefined1 *in_r1;
  undefined1 *in_r2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (in_r0 != 0) {
    puVar2 = in_r2 + in_r0;
    do {
      *in_r1 = *in_r2;
      if (puVar2 <= in_r2 + 1) {
        return;
      }
      in_r1[1] = in_r2[1];
      if (puVar2 <= in_r2 + 2) {
        return;
      }
      puVar1 = in_r2 + 3;
      in_r1[2] = in_r2[2];
      if (puVar2 <= puVar1) {
        return;
      }
      in_r2 = in_r2 + 4;
      in_r1[3] = *puVar1;
      in_r1 = in_r1 + 4;
    } while (in_r2 < puVar2);
  }
  return;
}



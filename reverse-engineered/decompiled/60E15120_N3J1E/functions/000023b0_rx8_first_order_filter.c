/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * First-order filter: current+(previous-current)*(1-coefficient), with invalid previous exponent rejection and snap-to-current threshold. Units of current/previous/threshold agree; coefficient is dimensionless. The raw C (uint)arg1 is an FPU bit reinterpretation in assembly, not a numeric uint conversion.
 */
/* ROM address: 0x000023b0; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023b0 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_first_order_filter(float current,float previous,float coefficient,float snap_threshold)

{
  float filtered;
  
  if ((((uint)previous & 0x7f800000) == 0x7f800000) ||
     (filtered = current + (previous - current) * (1.0 - coefficient), ABS(current - filtered) < snap_threshold)) {
    filtered = current;
  }
  return filtered;
}



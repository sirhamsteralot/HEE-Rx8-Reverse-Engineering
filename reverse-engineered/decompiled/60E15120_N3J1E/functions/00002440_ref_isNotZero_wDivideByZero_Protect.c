/* [MATH AND UNITS REVIEW]
 * rx8_is_outside_tolerance_band: Returns value < center-tolerance || value > center+tolerance. Inclusive endpoints are inside. Strict comparisons can both be false for NaN. Existing divide-by-zero-related name is too narrow: this helper itself performs no division.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002440; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002440 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 rx8_is_outside_tolerance_band(float value,float center,float tolerance)

{
  undefined4 outside_band;
  
  if ((value < center - tolerance) || (center + tolerance < value)) {
    outside_band = 1;
  }
  else {
    outside_band = 0;
  }
  return outside_band;
}



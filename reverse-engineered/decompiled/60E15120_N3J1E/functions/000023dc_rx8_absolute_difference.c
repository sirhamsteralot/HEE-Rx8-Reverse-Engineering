/* [MATH AND UNITS REVIEW]
 * Absolute difference is fabsf(a-b) behavior for ordinary values, implemented with SH FPU arithmetic. This is not a one-argument fabsf routine and does not establish a libm origin.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000023dc; body bytes: 8; decompiled */

float rx8_absolute_difference(float left,float right)

{
  return ABS(left - right);
}



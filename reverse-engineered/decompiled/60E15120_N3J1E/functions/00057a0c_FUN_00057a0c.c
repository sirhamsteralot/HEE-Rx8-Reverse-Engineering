/* [ADDITIONAL SOURCE REVIEW]
 * diag_append_u16_be [high]: G-ROM 0x55ecc matches after masking PC-relative literal displacement; C explicitly emits high then low byte and appends length 2.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00057a0c; body bytes: 34; decompiled */

void diag_append_u16_be(uint32_t service,uint32_t value)

{
  undefined1 high_byte;
  undefined1 low_byte;
  
  high_byte = (undefined1)((uint)value >> 8);
  low_byte = (undefined1)value;
  ref_setupForUdsResponse_(service,&high_byte,2);
  return;
}



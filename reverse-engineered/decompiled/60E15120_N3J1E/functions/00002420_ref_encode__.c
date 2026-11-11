/* [MATH AND UNITS REVIEW]
 * rx8_pack_u8_with_complement: Returns ((x & 255)<<8) | ((~x)&255). Redundant value/complement encoding, not byte swapping or a CRC.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002420; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002420 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_pack_u8_with_complement(uint value)

{
  return (value & 0xff) * 0x100 + (~value & 0xff);
}



/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_pack_u16_with_complement: Returns ((uint32)(uint16)x<<16) | (uint16)~x. Redundant value/complement encoding; raw signed return type can obscure bit-pattern semantics.
 */
/* ROM address: 0x00002430; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002430 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_pack_u16_with_complement(ushort value)

{
  return (uint)value * 0x10000 + (uint)(ushort)~value;
}



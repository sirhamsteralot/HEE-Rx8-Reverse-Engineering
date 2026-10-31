/* ROM address: 0x00002624; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002624 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0x2624-2656: R0 count/index, R1 axis, FR0 value/fraction. Endpoint paths set FR0=0; interior path divides breakpoint differences. No empty-axis guard is present. Struct return models two hardware outputs, not a native C ABI claim.
 * Explicit register-result structs are an analysis representation.
 */
Rx8AxisPosition rx8_find_axis_index_fraction(uint32_t count, const float *axis, float value)
{
  uint32_t byte_offset = (count - 1u) * 4u;
  float lower = *(const float *)((uintptr_t)axis + byte_offset);
  /* BF after FCMP/GT includes unordered comparisons: do not replace with <=. */
  if (!(lower > value)) return (Rx8AxisPosition){byte_offset >> 2, 0.0f};
  for (;;) {
    if (byte_offset == 0) return (Rx8AxisPosition){0, 0.0f};
    byte_offset -= 4u;
    lower = *(const float *)((uintptr_t)axis + byte_offset);
    if (!(lower > value)) break;
  }
  float upper = *(const float *)((uintptr_t)axis + byte_offset + 4u);
  return (Rx8AxisPosition){byte_offset >> 2, (value - lower) / (upper - lower)};
}


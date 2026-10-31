/* [MATH AND UNITS REVIEW]
 * rx8_insertion_sort_u16_key_u8_payload: Sorts records at stride 4 by ascending uint16 key, carrying a byte at offset 2. Strict-less comparison preserves equal-key order. Padding byte is not copied by the visible routine. Specialized insertion sort, not a proven qsort implementation.
 */
/* ROM address: 0x0006689e; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006518e (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [SORT RECORD RECONSTRUCTION] Typed equivalent for ordinary RAM records.
 * Four-byte stride, strict key comparison, low-16-bit count and untouched padding.
 * Volatile memory/interruption behavior is outside this reconstruction. */
void rx8_insertion_sort_u16_key_u8_payload(Rx8KeyPayloadRecord *records, uint32_t count)
{
  count &= 0xffffu;
  for (uint32_t insertion_index = 1; insertion_index < count; ++insertion_index) {
    uint16_t pending_key = records[insertion_index].key;
    uint8_t pending_payload = records[insertion_index].payload;
    uint32_t destination_index = insertion_index;
    while (destination_index != 0 && pending_key < records[destination_index - 1].key) {
      records[destination_index].key = records[destination_index - 1].key;
      records[destination_index].payload = records[destination_index - 1].payload;
      --destination_index;
    }
    records[destination_index].key = pending_key;
    records[destination_index].payload = pending_payload;
  }
  /* Padding bytes stay at their original locations, matching the ROM stores. */
}


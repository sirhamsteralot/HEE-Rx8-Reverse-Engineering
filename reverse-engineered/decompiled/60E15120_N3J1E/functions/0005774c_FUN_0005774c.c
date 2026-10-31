/* [ADDITIONAL SOURCE REVIEW]
 * diag22_find_and_dispatch_identifier [high]: Searches 99 records of 12 bytes at 0x5f10c, compares identifier 0xffffd1ea, checks permission mask, calls handler with service 0x22. G-ROM PID struct corroborates layout. Raw return/ABI still imperfect.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005774c; body bytes: 232; decompiled */

int diag22_find_and_dispatch_identifier(void)

{
  const Rx8DiagnosticRecord *records = RX8_ROM_PTR(Rx8DiagnosticRecord, 0x0005f10c);
  bool identifier_found;
  int unresolved_response_result;
  byte record_index;
  
  record_index = 0;
  identifier_found = false;
  while ((record_index < RX8_DIAGNOSTIC_RECORD_COUNT && (!identifier_found))) {
    if (records[record_index].identifier == diag22_current_identifier_ffffd1ea) {
      identifier_found = true;
      if ((records[record_index].availability_mask & DAT_ffffd3b4) == 0) {
        unresolved_response_result = ref_udsErrorResponse(RX8_SERVICE_READ_DATA,RX8_DIAG_IDENTIFIER_REJECTED);
      }
      else {
        if (DAT_ffffd1e8 != -0x80) {
          diag22_append_positive_response_header();
        }
        ((Rx8DiagnosticHandler)(uintptr_t)records[record_index].handler_address)(RX8_SERVICE_READ_DATA);
        if (DAT_ffffd1e8 == '\0') {
          unresolved_response_result = records[record_index].response_length + RX8_DIAG_READ_HEADER_SIZE;
        }
        else if (DAT_ffffd1e8 == -1) {
          ref_unknownMode22Func(RX8_SERVICE_READ_DATA);
          unresolved_response_result = ref_udsErrorResponse(RX8_SERVICE_READ_DATA);
        }
      }
    }
    record_index = record_index + 1;
  }
  if (!identifier_found) {
    unresolved_response_result = ref_udsErrorResponse(RX8_SERVICE_READ_DATA,RX8_DIAG_IDENTIFIER_REJECTED);
  }
  return unresolved_response_result;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_append_positive_response_header [high]: G-ROM 0x55d24 match plus explicit bytes 0x62 and current identifier RAM 0xffffd1ea.
 * RAM 0xffffd1ea diag22_current_identifier (uint16): Read from request by 0x567e8, matched by 0x5774c, echoed in 0x62 header.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00057858; body bytes: 44; decompiled */

void diag22_append_positive_response_header(void)

{
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  local_c = RX8_POSITIVE_READ_DATA_RESPONSE;
  uStack_b = (undefined1)((ushort)diag22_current_identifier_ffffd1ea >> 8);
  uStack_a = (undefined1)diag22_current_identifier_ffffd1ea;
  ref_setupForUdsResponse_(RX8_SERVICE_READ_DATA,&local_c,3);
  return;
}



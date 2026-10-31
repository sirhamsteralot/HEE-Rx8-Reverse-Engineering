/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000526d8; body bytes: 86; decompiled */

char FUN_000526d8(void)

{
  char cVar1;
  float snapshot_DAT_ffffcfe4;
  
  cVar1 = DAT_ffffcf86;
  if (DAT_ffffcf86 == '\x01') {
    snapshot_DAT_ffffcfe4 = DAT_ffffcfe4;
    if (DAT_ffffcfe4 < 0.015) {
      cVar1 = ref_getFaultStatus__(0x75);
      if (cVar1 == '\0') {
        DAT_ffffd10f = 1;
      }
    }
    if (0.0366 < snapshot_DAT_ffffcfe4) {
      cVar1 = ref_getFaultStatus__(0x76);
      if (cVar1 == '\0') {
        DAT_ffffd110 = 1;
      }
    }
  }
  return cVar1;
}



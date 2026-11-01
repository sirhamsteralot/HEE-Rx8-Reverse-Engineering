/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002eb1c; body bytes: 126; decompiled */

void FUN_0002eb1c(void)

{
  float snapshot_inferred_throttle_position_ffffad44;
  
  if (((DAT_ffffbd6c < 0x9d) || (60.06 <= DAT_ffffbd78)) || (inferred_throttle_position_ffffad44 < 60.06)) {
    if (((0x9c < DAT_ffffbd6c) || (inferred_throttle_position_ffffad44 <= 45.045)) ||
       ((0x5e < DAT_ffffbd6c && (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\x01')))) {
      DAT_ffffbd72 = 0;
    }
  }
  else {
    DAT_ffffbd72 = 1;
    DAT_ffffbd6c = 0;
  }
  snapshot_inferred_throttle_position_ffffad44 = inferred_throttle_position_ffffad44;
  DAT_ffffbd6c = rx8_add_u16_saturate((int)(short)DAT_ffffbd6c,1);
  DAT_ffffbd78 = snapshot_inferred_throttle_position_ffffad44;
  return;
}



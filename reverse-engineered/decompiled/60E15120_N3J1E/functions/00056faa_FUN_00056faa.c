/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid16b3_ram_ad10_raw [high]: dispatch record 0x5f3ac -> handler verified in ROM bytes + function_index; DAT_ffffad10*7.62939e-05 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_ad10_ffffad10_ffffad10; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056faa; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3ac. Table purpose inferred from
   neighboring code. */

void diag22_pid16b3_ram_ad10_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_ad10_ffffad10_ffffad10,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



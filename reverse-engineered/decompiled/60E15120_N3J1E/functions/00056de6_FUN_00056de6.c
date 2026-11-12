/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid091a_ram_b410_raw_512 [high]: dispatch record 0x5f310 -> handler verified in ROM bytes + function_index; DAT_ffffb410*0.00195312 (1/512) | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_b410_ffffb410_ffffb410; decode = raw * 0.001953125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056de6; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f310. Table purpose inferred from
   neighboring code. */

void diag22_pid091a_ram_b410_raw_512(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_b410_ffffb410_ffffb410,0x3b000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



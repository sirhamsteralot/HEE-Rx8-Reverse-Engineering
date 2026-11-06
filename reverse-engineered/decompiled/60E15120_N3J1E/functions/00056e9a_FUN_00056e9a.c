/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1153_ram_a834_lambda [medium]: dispatch record 0x5f358 -> handler verified in ROM bytes + function_index; DAT_ffffa834*3.05176e-05
 * RAM 0xffffa834 inferred_ram_a834_ffffa834 (float): PID 0x1153 *3.05e-05
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffa834; decode = raw * 3.051757812e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e9a; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f358. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pid1153_ram_a834_lambda(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_a834_ffffa834_ffffa834,0x38000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



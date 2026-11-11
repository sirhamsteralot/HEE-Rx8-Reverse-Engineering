/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1340_ram_a9bc_pct [high]: dispatch record 0x5f388 -> handler verified in ROM bytes + function_index; DAT_ffffa9bc*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffa9bc inferred_ram_a9bc_ffffa9bc (float): PID 0x1340 *0.392157
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffa9bc; decode = raw * 0.3921568394 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056f4e; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f388. Table purpose inferred from
   neighboring code. */

void diag22_pid1340_ram_a9bc_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_ram_a9bc_ffffa9bc_ffffa9bc,0x3ec8c8c8,0);
  diag_append_u8((int)param_1,uVar1);
  return;
}



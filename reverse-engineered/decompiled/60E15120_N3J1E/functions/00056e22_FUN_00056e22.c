/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid096e_ram_a7ac_quarter [high]: dispatch record 0x5f328 -> handler verified in ROM bytes + function_index; inferred_ram_a7ac_ffffa7ac_ffffa7ac*0.25 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffa7ac inferred_ram_a7ac_ffffa7ac (float): PID 0x096e *0.25
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_a7ac_ffffa7ac_ffffa7ac; decode = raw * 0.25 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e22; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f328. Table purpose inferred from
   neighboring code. */

void diag22_pid096e_ram_a7ac_quarter(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_a7ac_ffffa7ac_ffffa7ac,0x3e800000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid114a_ram_add4_raw [high]: dispatch record 0x5f340 -> handler verified in ROM bytes + function_index; inferred_ram_add4_ffffadd4_ffffadd4*7.62939e-05 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffadd4 inferred_ram_add4_ffffadd4 (float): PID 0x114a *7.63e-05
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_add4_ffffadd4_ffffadd4; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e5e; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f340. Table purpose inferred from
   neighboring code. */

void diag22_pid114a_ram_add4_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_add4_ffffadd4_ffffadd4,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



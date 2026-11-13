/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid114d_ram_a984_raw [high]: dispatch record 0x5f34c -> handler verified in ROM bytes + function_index; inferred_ram_a984_ffffa984_ffffa984*7.62939e-05 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffa984 inferred_ram_a984_ffffa984 (float): PID 0x114d
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_a984_ffffa984_ffffa984; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e7c; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f354 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid114d_ram_a984_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_a984_ffffa984_ffffa984,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



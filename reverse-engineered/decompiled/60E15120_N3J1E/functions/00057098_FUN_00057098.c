/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1782_ram_c6ac_raw [high]: dispatch record 0x5f3f4 -> handler verified in ROM bytes + function_index; inferred_ram_c6ac_ffffc6ac_ffffc6ac*7.62939e-05 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffc6ac inferred_ram_c6ac_ffffc6ac (float): PID 0x1782
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_c6ac_ffffc6ac_ffffc6ac; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00057098; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f3fc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1782_ram_c6ac_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_c6ac_ffffc6ac_ffffc6ac,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



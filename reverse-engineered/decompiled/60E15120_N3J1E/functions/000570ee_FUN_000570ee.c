/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid172a_ram_c4c8_temp_c [high]: dispatch record 0x5f40c -> handler verified in ROM bytes + function_index; inferred_temp_c4c8_ffffc4c8_ffffc4c8*1.0-40 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffc4c8 inferred_temp_c4c8_ffffc4c8 (float): PID 0x172a: x-40
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): inferred_temp_c4c8_ffffc4c8_ffffc4c8; decode = raw * 1 + (-40) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000570ee; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f414 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid172a_ram_c4c8_temp_c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_temp_c4c8_ffffc4c8_ffffc4c8,0x3f800000,0xc2200000);
  diag_append_u8((int)param_1,uVar1);
  return;
}



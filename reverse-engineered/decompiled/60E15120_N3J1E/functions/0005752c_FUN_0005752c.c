/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pide21d_cal_id_chunk_2 [high]: dispatch record 0x5f4fc -> handler verified in ROM bytes + function_index; appends '8','8','1'
 */
/* ROM address: 0x0005752c; body bytes: 26; decompiled */

/* Function candidate recovered from ROM pointer at 5f504 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pide21d_cal_id_chunk_2(undefined4 param_1)

{
  diag_append_u8(param_1,0x38);
  diag_append_u8(param_1,0x38);
  diag_append_u8(param_1,0x31);
  return;
}



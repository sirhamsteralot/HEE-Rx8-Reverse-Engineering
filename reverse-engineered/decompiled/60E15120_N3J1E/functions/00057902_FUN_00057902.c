/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff41_fw_id_chunk_120 [high]: dispatch record 0x5f574 -> handler verified in ROM bytes + function_index; appends '1','2','0',' '
 */
/* ROM address: 0x00057902; body bytes: 44; decompiled */

/* Function candidate recovered from ROM pointer at 5f57c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidff41_fw_id_chunk_120(undefined4 param_1)

{
  diag_append_u8(param_1,0x31);
  diag_append_u8(param_1,0x32);
  diag_append_u8(param_1,0x30);
  diag_append_u8(param_1,0x20);
  return;
}



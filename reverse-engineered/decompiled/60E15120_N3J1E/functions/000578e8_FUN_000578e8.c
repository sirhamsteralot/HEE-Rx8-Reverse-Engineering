/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff40_fw_id_chunk_15 [high]: dispatch record 0x5f568 -> handler verified in ROM bytes + function_index; appends '1','5' (fw id '60E15120' ROM 0x2000; cal area 0x6c05c '15120 ')
 */
/* ROM address: 0x000578e8; body bytes: 26; decompiled */

/* Function candidate recovered from ROM pointer at 5f570 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidff40_fw_id_chunk_15(char param_1)

{
  diag_append_u8((int)param_1,0x31);
  diag_append_u8((int)param_1,0x35);
  return;
}



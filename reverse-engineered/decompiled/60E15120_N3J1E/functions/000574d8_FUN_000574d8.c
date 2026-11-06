/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pide21b_cal_id_chunk_0 [high]: dispatch record 0x5f4e4 -> handler verified in ROM bytes + function_index; appends immediates 'N','3','Z','H' (cal ID at ROM 0x6c046 'N3ZHEB000.HEX')
 */
/* ROM address: 0x000574d8; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5f4ec and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pide21b_cal_id_chunk_0(undefined4 param_1)

{
  diag_append_u8(param_1,0x4e);
  diag_append_u8(param_1,0x33);
  diag_append_u8(param_1,0x5a);
  diag_append_u8(param_1,0x48);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0020_pids_supported_21_40 [high]: dispatch record 0x5f1e4 -> handler verified in ROM bytes + function_index; handler appends const u16 0x8007,0xB011 = supported-PID bitmap 21-40
 */
/* ROM address: 0x00056a84; body bytes: 36; decompiled */

/* Function candidate recovered from ROM pointer at 5f1ec and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0020_pids_supported_21_40(char param_1)

{
  diag_append_u16_be((int)param_1,0x8007);
  diag_append_u16_be((int)param_1,0x8007b011);
  return;
}



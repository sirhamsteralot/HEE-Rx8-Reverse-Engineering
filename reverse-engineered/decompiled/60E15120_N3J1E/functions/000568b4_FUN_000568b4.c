/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0002_active_cal_id_field [medium]: dispatch record 0x5f118 -> handler verified in ROM bytes + function_index; reader 0x55316: 0x61af4->0x6071e scans cal-descriptor table (DAT_0007e704), 0x54994 TLV-extracts tag 2 (2 bytes) from ROM info block
 */
/* ROM address: 0x000568b4; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f120 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid0002_active_cal_id_field(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_read_active_cal_field();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



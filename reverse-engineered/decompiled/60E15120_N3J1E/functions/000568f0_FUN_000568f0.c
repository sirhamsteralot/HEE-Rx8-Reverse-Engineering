/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0004_calculated_engine_load_pct [high]: dispatch record 0x5f130 -> handler verified in ROM bytes + function_index; 0x553dc: engine_load_ffffc0b4*100/engine_load_max_ffffc0b8*0.392157 = OBD PID 04 A*100/max; 0xff if max~0
 */
/* ROM address: 0x000568f0; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f138 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0004_calculated_engine_load_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_calc_load_pct();
  diag_append_u8((int)param_1,uVar1);
  return;
}



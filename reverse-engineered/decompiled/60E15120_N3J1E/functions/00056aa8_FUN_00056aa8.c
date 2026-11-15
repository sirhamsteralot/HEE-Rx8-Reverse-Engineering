/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0021_distance_while_mil_on [high]: dispatch record 0x5f1f0 -> handler verified in ROM bytes + function_index; 0x555f8: DAT_ffff90f4 float*1.0 = OBD PID 21
 */
/* ROM address: 0x00056aa8; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f1f8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0021_distance_while_mil_on(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_distance_mil();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



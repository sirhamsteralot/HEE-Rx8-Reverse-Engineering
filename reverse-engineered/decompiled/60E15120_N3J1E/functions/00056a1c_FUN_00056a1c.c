/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0013_o2_sensors_present [high]: dispatch record 0x5f1b4 -> handler verified in ROM bytes + function_index; const 2 = OBD PID 13 bitmap (bank1 sensors)
 */
/* ROM address: 0x00056a1c; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f1bc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0013_o2_sensors_present(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_o2_present_const();
  diag_append_u8((int)param_1,uVar1);
  return;
}



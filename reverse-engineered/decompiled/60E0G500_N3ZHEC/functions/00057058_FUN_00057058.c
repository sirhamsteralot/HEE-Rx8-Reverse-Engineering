/* ROM address: 0x00057058; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f8c4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0002_active_cal_id_field(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_active_cal_field();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



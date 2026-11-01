/* ROM address: 0x0005724c; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f99c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0021_distance_while_mil_on(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_distance_mil();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



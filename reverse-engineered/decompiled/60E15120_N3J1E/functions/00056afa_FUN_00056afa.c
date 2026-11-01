/* ROM address: 0x00056afa; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f228 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid0031_ram_90fc_float(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_read_90fc();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



/* ROM address: 0x00057458; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa74 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0202_dtc_count_ram_list(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = dtc_count_ram_table();
  diag_append_u8((int)param_1,uVar1);
  return;
}



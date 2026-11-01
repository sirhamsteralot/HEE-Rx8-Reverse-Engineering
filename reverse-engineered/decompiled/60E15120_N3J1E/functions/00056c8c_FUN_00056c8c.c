/* ROM address: 0x00056c8c; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid004c_ram_b410_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_encode_b410();
  diag_append_u8((int)param_1,uVar1);
  return;
}



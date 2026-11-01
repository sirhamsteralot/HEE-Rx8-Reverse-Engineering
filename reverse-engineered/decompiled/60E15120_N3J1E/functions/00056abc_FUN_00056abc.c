/* ROM address: 0x00056abc; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f204 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid002e_ram_b2f0_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_encode_b2f0();
  diag_append_u8((int)param_1,uVar1);
  return;
}



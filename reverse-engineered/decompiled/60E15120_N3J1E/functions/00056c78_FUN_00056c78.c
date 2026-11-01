/* ROM address: 0x00056c78; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2ac and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid004a_ram_a9c6_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_encode_a9c6();
  diag_append_u8((int)param_1,uVar1);
  return;
}



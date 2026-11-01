/* ROM address: 0x00057738; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f558 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pidc124_diag_status_bits(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_status_bit_pack();
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* ROM address: 0x00057226; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f45c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1102_io_status_bdb8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag22_subpid_supported_mask(inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\x01',1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



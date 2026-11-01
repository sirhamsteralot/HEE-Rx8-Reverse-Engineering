/* ROM address: 0x000574b6; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f4e0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid17de_io_status_ce32(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag22_subpid_supported_mask(inferred_ram_ce32_ffffce32_ffffce32 == '\x01',1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



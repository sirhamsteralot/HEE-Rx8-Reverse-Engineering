/* ROM address: 0x0005734a; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f48c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1681_io_status_ce1c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (inferred_ram_ce1c_ffffce1c_ffffce1c == '\x01') {
    uVar1 = 0x40;
  }
  uVar1 = diag22_subpid_supported_mask(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



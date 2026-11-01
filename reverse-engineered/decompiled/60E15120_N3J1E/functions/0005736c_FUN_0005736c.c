/* ROM address: 0x0005736c; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f498 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1688_secondary_air_status_bit(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (secondary_air_request_final_ffffa960 == '\x01') {
    uVar1 = 0x20;
  }
  uVar1 = diag22_subpid_supported_mask(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



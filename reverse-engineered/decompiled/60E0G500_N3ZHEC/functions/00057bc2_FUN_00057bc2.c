/* ROM address: 0x00057bc2; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc60 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1706_io_status_a8f5(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffa976 == '\x01') {
    uVar1 = 4;
  }
  uVar1 = diag22_subpid_supported_mask(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* ROM address: 0x00057aee; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc30 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1681_io_status_ce1c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffce58 == '\x01') {
    uVar1 = 0x40;
  }
  uVar1 = diag22_subpid_supported_mask(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



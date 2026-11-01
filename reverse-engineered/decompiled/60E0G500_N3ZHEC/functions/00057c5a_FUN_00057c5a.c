/* ROM address: 0x00057c5a; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc84 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid17de_io_status_ce32(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag22_subpid_supported_mask(DAT_ffffce6e == '\x01',1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



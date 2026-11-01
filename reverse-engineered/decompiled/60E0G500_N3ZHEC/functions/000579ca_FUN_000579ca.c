/* ROM address: 0x000579ca; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc00 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1102_io_status_bdb8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag22_subpid_supported_mask(DAT_ffffbe24 == '\x01',1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



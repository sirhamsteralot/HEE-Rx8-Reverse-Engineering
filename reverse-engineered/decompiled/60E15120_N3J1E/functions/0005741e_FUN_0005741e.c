/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1706_io_status_a8f5 [medium]: dispatch record 0x5f4b4 -> handler verified in ROM bytes + function_index; 0x579a8 over DAT_ffffa8f5 -> 4
 * RAM 0xffffa8f5 inferred_ram_a8f5_ffffa8f5 (uint8): PID 0x1706 -> bit 4
 */
/* ROM address: 0x0005741e; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f4bc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1706_io_status_a8f5(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (inferred_ram_a8f5_ffffa8f5_ffffa8f5 == '\x01') {
    uVar1 = 4;
  }
  uVar1 = diag22_subpid_supported_mask(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



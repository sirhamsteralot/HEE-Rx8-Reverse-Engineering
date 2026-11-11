/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1102_io_status_bdb8 [high]: dispatch record 0x5f454 -> handler verified in ROM bytes + function_index; 0x579a8 over DAT_ffffbdb8 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffbdb8 inferred_ram_bdb8_ffffbdb8 (uint8): PID 0x1102
 */
/* ROM address: 0x00057226; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f45c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1102_io_status_bdb8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag22_subpid_supported_mask(inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\x01',1);
  diag_append_u8((int)param_1,uVar1);
  return;
}



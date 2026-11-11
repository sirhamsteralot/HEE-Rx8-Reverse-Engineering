/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1688_secondary_air_status_bit [high]: dispatch record 0x5f490 -> handler verified in ROM bytes + function_index; 0x579a8 over secondary_air_request_final_ffffa960 -> 0x20 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x0005736c; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f498 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1688_secondary_air_status_bit(char param_1)

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



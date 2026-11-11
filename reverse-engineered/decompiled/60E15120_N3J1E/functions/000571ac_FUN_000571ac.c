/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid09d3_pedr_bit10_status [high]: dispatch record 0x5f43c -> handler verified in ROM bytes + function_index; PEDR_W & 0x400 -> 0x579a8; appends u8 + 0 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x000571ac; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5f444 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid09d3_pedr_bit10_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = PEDR_W;
  uVar2 = diag22_subpid_supported_mask((uVar1 & 0x400) != 0,1);
  diag_append_u8((int)param_1,uVar2);
  diag_append_u8((int)param_1,0);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1711_pedr_bit1_status [high]: dispatch record 0x5f4a8 -> handler verified in ROM bytes + function_index; 0x579a8 over PEDR_W & 2 -> 0x80 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x000573f0; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5f4b0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1711_pedr_bit1_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = PEDR_W;
  if ((uVar1 & 2) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = diag22_subpid_supported_mask(uVar2,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}



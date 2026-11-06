/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1718_pedr_bit2_status [medium]: dispatch record 0x5f4c0 -> handler verified in ROM bytes + function_index; 0x579a8 over PEDR_W & 4
 */
/* ROM address: 0x00057440; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5f4c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1718_pedr_bit2_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = PEDR_W;
  uVar2 = diag22_subpid_supported_mask((uVar1 & 4) != 0,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}



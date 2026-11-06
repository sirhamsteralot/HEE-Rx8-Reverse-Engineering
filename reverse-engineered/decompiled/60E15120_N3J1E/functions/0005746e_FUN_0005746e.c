/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1715_pedr_pddr_status [medium]: dispatch record 0x5f4cc -> handler verified in ROM bytes + function_index; 0x579a8 over PEDR_W & 0x80 -> 0x40, PDDR_W & 0x20 -> 0x80
 */
/* ROM address: 0x0005746e; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5f4d4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1715_pedr_pddr_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = PEDR_W;
  if ((uVar1 & 0x80) != 0) {
    uVar3 = 0x40;
  }
  uVar1 = PDDR_W;
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar2 = diag22_subpid_supported_mask(uVar3,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1104_io_status_pjdr_bf6c [high]: dispatch record 0x5f46c -> handler verified in ROM bytes + function_index; 0x579a8 over PJDR_W bit0x80, secondary_air_pump_request_ffffbf6c | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x000572d0; body bytes: 62; decompiled */

/* Function candidate recovered from ROM pointer at 5f474 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1104_io_status_pjdr_bf6c(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = PJDR_W;
  bVar3 = (uVar1 & 0x80) != 0;
  if (secondary_air_pump_request_ffffbf6c == '\x01') {
    bVar3 = bVar3 | 0x10;
  }
  uVar2 = diag22_subpid_supported_mask(bVar3,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}



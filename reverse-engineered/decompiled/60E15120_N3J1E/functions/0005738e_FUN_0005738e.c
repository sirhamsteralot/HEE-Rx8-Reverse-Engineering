/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pida211_status_b53b_aa62_bf9c [medium]: dispatch record 0x5f49c -> handler verified in ROM bytes + function_index; 0x579a8 sub1 over ffffb53b(4)/ffffaa62(0x10), sub2 over ffffbf9c; appends 2 u8
 * RAM 0xffffb53b inferred_ram_b53b_ffffb53b (uint8): PID 0xa211 -> bit 4
 * RAM 0xffffaa62 cranking_active_ffffaa62 (uint8): PID 0xa211 -> bit 0x10 when 0; named by ignition report (cranking multiplier decay)
 * RAM 0xffffbf9c inferred_ram_bf9c_ffffbf9c (uint8): PID 0xa211 sub2
 */
/* ROM address: 0x0005738e; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5f4a4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pida211_status_b53b_aa62_bf9c(char param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (inferred_ram_b53b_ffffb53b_ffffb53b == '\x01') {
    uVar2 = 4;
  }
  if (cranking_active_ffffaa62_ffffaa62 == '\0') {
    uVar2 = uVar2 | 0x10;
  }
  uVar1 = diag22_subpid_supported_mask(uVar2,1);
  diag_append_u8((int)param_1,uVar1);
  uVar1 = diag22_subpid_supported_mask(inferred_ram_bf9c_ffffbf9c_ffffbf9c == '\x01',2);
  diag_append_u8((int)param_1,uVar1);
  return;
}



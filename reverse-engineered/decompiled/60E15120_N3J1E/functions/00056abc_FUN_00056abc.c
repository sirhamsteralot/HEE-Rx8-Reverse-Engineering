/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid002e_ram_b2f0_pct [high]: dispatch record 0x5f1fc -> handler verified in ROM bytes + function_index; 0x55616: inferred_ram_b2f0_ffffb2f0_ffffb2f0*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056abc; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f204 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid002e_ram_b2f0_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_b2f0();
  diag_append_u8((int)param_1,uVar1);
  return;
}



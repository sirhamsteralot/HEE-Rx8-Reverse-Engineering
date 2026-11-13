/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid004c_ram_b410_pct [high]: dispatch record 0x5f2b0 -> handler verified in ROM bytes + function_index; 0x55864: inferred_ram_b410_ffffb410_ffffb410*100/84*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056c8c; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid004c_ram_b410_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_b410();
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid004a_ram_a9c6_pedal [high]: dispatch record 0x5f2a4 -> handler verified in ROM bytes + function_index; 0x55838: DAT_ffffa9c6 decode(7.63e-05)*20*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056c78; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2ac and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid004a_ram_a9c6_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_a9c6();
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0049_ram_a9c4_pedal [high]: dispatch record 0x5f298 -> handler verified in ROM bytes + function_index; 0x557b6: inferred_pedal_volts_ffffa9c4_ffffa9c4 decode(7.63e-05)*20*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056bda; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2a0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0049_ram_a9c4_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_a9c4();
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0202_dtc_count_ram_list [high]: dispatch record 0x5f2c8 -> handler verified in ROM bytes + function_index; 0x5fb08 counts dtc_ram_flag_table_ffffd570_ffffd570[0..0x8b]==1 minus rotor-0/1 adjustments, clamp 0xff
 */
/* ROM address: 0x00056cb4; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2d0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0202_dtc_count_ram_list(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = dtc_count_ram_table();
  diag_append_u8((int)param_1,uVar1);
  return;
}



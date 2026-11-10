/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid002e_ram_b2f0_pct [medium]: dispatch record 0x5f1fc -> handler verified in ROM bytes + function_index; 0x55616: DAT_ffffb2f0*0.392157
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



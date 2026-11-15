/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0007_ltft_bank1_pct [high]: dispatch record 0x5f154 -> handler verified in ROM bytes + function_index; 0x55466: DAT_ffffb0d0*100*0.78125-100; OBD PID 07 trim formula
 */
/* ROM address: 0x0005696c; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f15c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0007_ltft_bank1_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ltft();
  diag_append_u8((int)param_1,uVar1);
  return;
}



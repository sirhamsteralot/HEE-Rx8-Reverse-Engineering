/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0006_stft_bank1_pct [high]: dispatch record 0x5f148 -> handler verified in ROM bytes + function_index; 0x55440: (DAT_ffffadec-1)*100*0.78125-100; ffffadec=lambda actual (fuel chain); OBD PID 06 trim formula
 */
/* ROM address: 0x00056956; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f150 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0006_stft_bank1_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_stft_lambda();
  diag_append_u8((int)param_1,uVar1);
  return;
}



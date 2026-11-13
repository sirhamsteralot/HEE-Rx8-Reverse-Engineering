/* [ADDITIONAL SOURCE REVIEW]
 * diag_lambda_target [high]: RomRaider PID 0x0044 'Lambda Target' handler: encodes lambda_target_ffffadfc (step 0x38000000) as u16 BE.
 * diag22_pid0044_lambda_target [high]: dispatch record 0x5f274 -> handler verified in ROM bytes + function_index; 0x5575e: lambda_target_ffffadfc*3.05176e-05 (logger 0x220044)
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0044: Lambda Target. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056b9e; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f27c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0044_lambda_target(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_lambda_target();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



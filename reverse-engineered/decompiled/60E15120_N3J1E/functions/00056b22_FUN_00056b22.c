/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0034_afr_lambda_words [high]: dispatch record 0x5f238 -> handler verified in ROM bytes + function_index; diag_air_fuel_ratio 0x56b22 appends diag_afr_word_a_ffffaa6c and diag_afr_word_b_ffffaa7c (logger 0x220034 AFR, x*3.05e-05)
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0034: Air Fuel Ratio. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056b22; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 5f240 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0034_afr_lambda_words(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_afr_word_a();
  diag_append_u16_be((int)param_1,uVar1);
  uVar1 = diag_read_afr_word_b();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



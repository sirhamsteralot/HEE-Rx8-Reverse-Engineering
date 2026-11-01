/* [ADDITIONAL SOURCE REVIEW]
 * diag_air_fuel_ratio [high]: RomRaider PID 0x0034 'Air Fuel Ratio' handler: packs FUN_000556ec (DAT_ffffaa6c) and FUN_00055702 (DAT_ffffaa7c) as two u16 BE words.
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
  
  uVar1 = candidate_diag_afr_word_a();
  diag_append_u16_be((int)param_1,uVar1);
  uVar1 = candidate_diag_afr_word_b();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}



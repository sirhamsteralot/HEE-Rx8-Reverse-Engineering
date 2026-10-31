/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0005: Coolant Temp. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056940; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f144 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag_read_coolant_temp(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0005542a();
  diag_append_u8((int)param_1,uVar1);
  return;
}



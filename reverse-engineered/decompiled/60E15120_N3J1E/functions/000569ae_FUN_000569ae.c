/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x000e: Leading Ignition Timing. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x000569ae; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f180 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag_read_leading_ignition_timing(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000554ae();
  diag_append_u8((int)param_1,uVar1);
  return;
}



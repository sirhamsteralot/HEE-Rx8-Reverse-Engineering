/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0904_trailing_ignition_timing_deg [high]: dispatch record 0x5f2d4 -> handler verified in ROM bytes + function_index; trailing_ignition_timing_ffffa638*0.5-64 (logger 0x220904)
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0904: Trailing Ignition Timing. Dispatch identifier match; logger meaning is definition-derived.
 * RX8Defs diagnostic chain suggests RAM 0xffffa638 = trailing_ignition_timing. Direct C dataflow to handler 0x00056cc8; semantic candidate, not a recovered original symbol.
 */
/* ROM address: 0x00056cc8; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 5f2dc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0904_trailing_ignition_timing_deg(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(trailing_ignition_timing_ffffa638,0x3f000000,0xc2800000);
  diag_append_u8((int)param_1,uVar1);
  return;
}



/* ROM address: 0x00057152; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f924 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000e_leading_ignition_timing_deg(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_leading_timing();
  diag_append_u8((int)param_1,uVar1);
  return;
}



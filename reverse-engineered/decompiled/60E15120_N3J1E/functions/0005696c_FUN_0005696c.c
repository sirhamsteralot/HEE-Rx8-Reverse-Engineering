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



/* ROM address: 0x000570fa; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f8f4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0006_stft_bank1_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_stft_lambda();
  diag_append_u8((int)param_1,uVar1);
  return;
}



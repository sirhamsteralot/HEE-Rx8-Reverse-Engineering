/* ROM address: 0x000572c6; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 5f9e4 and register-save prologue. Heuristic
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


